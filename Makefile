CC = g++
CFLAGS = -Wall -Werror -g
OBJECTS = Lexer.cc Parser.cc Lexer.h

all: ws

ws: $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS)

clean:
	rm -f $(PROGS) *.o *~ ws
