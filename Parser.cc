#include <stdio.h>
#include <stdlib.h>
#include "Lexer.h"

// Convert tabs and spaces into a number using bit shifting.
// Tab == 1
// Space == 0
// Ignores all invalid characters and scans until a valid character
// is input.
int toInt(FILE* in) {
    char c;
    fscanf(in, "%c", &c);
    int i = 0;
    while (c != 10) {
        if (c == 9 || c == 32) {
            i <<= 1;
            if (c == 9) i |= 1;
        }
        fscanf(in, "%c", &c);
    }
    return i;
}

int main(int argc, char** argv) {
    // Exit if invalid input.
    if (argc != 2) {
        printf("Incorrect parameters given. Try again.\n");
        return 2;
    }
    
    FILE * in = fopen(argv[1], "r");
    // Exit if the file does not open.
    if (!in) {
        printf("%s could not be opened.\n", argv[1]);
        return 1;
    }
    
    
    
    // Step through the file.
    char c;
    fscanf(in, "%c", &c);
    while (!feof(in)) {

        // See what the first char is.
        switch (c) {
            // Tab
            case 9:
                char d;
                fscanf(in, "%c", &d);
                while (d != 32 && d != 9 && d != 10) fscanf(in, "%c", &d);
                // Space: Arithmetic
                if (d == 32) {
                    char j, k;
                    fscanf(in, "%c", &j);
                    //Loop until a valid input is found.
                    while (j != 32 && j != 9 && j != 10) fscanf(in, "%c", &j);
                    fscanf(in, "%c", &k);
                    //Loop until a valid input is found.
                    while (k != 32 && k != 9 && k != 10) fscanf(in, "%c", &k);

                    // Find what arithmetic funciton to call.
                    // Space
                    if (j == 32) {
                        // Space
                        if (k == 32) Addition();
                        // Tab
                        else if (k == 9) Subtraction();
                        // Line Feed
                        else if (k == 10) Multiplication();
                    } 
                    // Tab
                    else if (j == 9) {
                        // Space
                        if (k == 32) Division();
                        // Tab
                        else if (k == 9) Modulo();
                        else {
                            printf("Invalid Arithmetic function.\n");
                            return 0;
                        }
                    } 
                }

                // Heap Manipulation
                // Tab
                else if (d == 9) {
                    char l;
                    fscanf(in, "%c", &l);
                    //Loop until a valid input is found.
                    while (l != 32 && l != 9 && l != 10) fscanf(in, "%c", &l);
                    // Space
                    if (l == 32) HeapPush();
                    // Tab
                    else if (l == 9) HeapRetrieve();
                    else {
                        printf("Invalid Heap Access function.\n");
                        return 0;
                    }
                }

                // I/O
                // Line Feed
                else if (d == 10) {
                    char m, n;
                    fscanf(in, "%c", &m);
                    //Loop until a valid input is found.
                    while (m != 32 && m != 9 && m != 10) fscanf(in, "%c", &m);
                    fscanf(in, "%c", &n);
                    //Loop until a valid input is found.
                    while (n != 32 && n != 9 && n != 10) fscanf(in, "%c", &n);

                    // Input or output?
                    // Space
                    if (m == 32) {
                        // Space
                        if (n == 32) CharOut();
                        // Tab
                        else if (n == 9) IntOut();
                        else {
                            printf("Invalid IO function.\n");
                            return 0;
                        }
                    } 
                    // Tab
                    else if (m == 9) {
                        // Space
                        if (n == 32) CharIn();
                        // Tab
                        else if (n == 9) IntIn();
                        else {
                            printf("Invalid I/O function.\n");
                            return 0;
                        }
                    }
                }
                break;

            // Stack Manipulation.
            // Space
            case 32:
                char e;
                fscanf(in, "%c", &e);
                //Loop until a valid input is found.
                while (e != 32 && e != 9 && e != 10) fscanf(in, "%c", &e);
                
                // Space
                if (e == 32) StackPush(toInt(in));
                // Line Feed
                else if (e == 10) {
                    char n;
                    fscanf(in, "%c", &n);
                    //Loop until a valid input is found.
                    while (n != 32 && n != 9 && n != 10) fscanf(in, "%c", &n);
                    
                    // Line Feed
                    if (n == 10) StackPop();
                    else {
                        printf("Invalid Stack Manipulation function.\n");
                        return 0;
                    }
                } else {
                    printf("Invalid Stack Manipulation function.\n");
                    return 0;
                }
                break;
        }

        //Scan next char to see what next function call will be.
        fscanf(in, "%c", &c);
        
    }
}
