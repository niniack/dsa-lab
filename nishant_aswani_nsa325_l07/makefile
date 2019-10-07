#  File: makefile
#  Name: Nishant Aswani
#  Instructor: Cristoforos Vasilatos
#  Assignment: Lab 7
#  Course: Data Structures and Algorithms (ENGR-UH 3510) Fall 2019
#  Due: Oct 7 2019

PROG = lab7
OUT = lab7_output
CC = g++
CPPFLAGS = -g -Wall

all: generate write

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
