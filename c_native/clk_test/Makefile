# Simple Makefile
# 	Simply calling make from the command line will build the first target;
# 	in this case all
# 	Syntax:
# 		target:[space]<target/file dependencies>
# 		[one tab space]command to execute
# 	The dependencies forces the target to execute if any of the dependencies
# 	change
# 	Refn.: http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/

CC=gcc
CFLAGS=-Wall
SRCDIR=./src
OBJ=clk_test.o
EXE=clk_test

%.o: $(SRCDIR)/%.c
	$(CC) -g -Wall -c -o $@ $< $(CFLAGS)

all: $(OBJ)
	$(CC) $^ -o $(EXE)

.PHONY: clean

clean:
	rm -rf *.o $(EXE)
