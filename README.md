Whitespace-Interpreter
======================
  
What is Whitespace?  
http://compsoc.dur.ac.uk/whitespace/index.php  
  
Explanation of Whitespace functions:  
http://compsoc.dur.ac.uk/whitespace/tutorial.php  
  
My implementation of this Whitespace interpreter implements the required functions except:  
+ All flow control.  
+ Stack Manipulation:  
* Duplicating the top item on the stack.  
* Copying the nth item on the stack onto the top of the stack.  
* Swap the two top items on the stack.  
* Slide n items off the stack, keeping the top item.  
  
My design is very simple. There is a Parser.cc file that parses the file and sends out 
for the necessary functions. Lexor.cc is where all of the main functions are and where 
the stack and heap are stored. You can compile using my provided Makefile. All function 
names are very self explanatory.