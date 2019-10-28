#  File: makefile
#  Name: Nishant Aswani
#  Instructor: Cristoforos Vasilatos
#  Assignment: Lab 9
#  Course: Data Structures and Algorithms (ENGR-UH 3510) Fall 2019
#  Due: Oct 28 2019

PROG = lab9
OUT = lab9_output
CC = g++
CPPFLAGS = -g -Wall

all: generate run

generate :
	@echo "Compiling object..."
	${CC} $(CPPFLAGS) -o $(PROG) *.cpp

run :
	@echo "Running object in place..."
	./$(PROG)

write :
	@echo "Running object and saving text..."
	./$(PROG) -> $(OUT).txt

clean:
	@echo "Cleaning up..."
	rm -f core $(PROG) $(OBJS)
	rm $(OUT).txt
