#  File: makefile
#  Name: Nishant Aswani
#  Instructor: Cristoforos Vasilatos
#  Course: Data Structures and Algorithms (ENGR-UH 3510) Fall 2019
#  Due: Sep 2 2019

PROG = prelab2
OUT = prelab2_output
CC = g++
CPPFLAGS = -g -Wall

all: generate write

generate :
	@echo "Compiling object..."
	${CC} $(CPPFLAGS) -o $(PROG) *.cpp

write :
	@echo "Running object..."
	./$(PROG) -> $(OUT).txt

clean:
	@echo "Cleaning up..."
	rm -f core $(PROG) $(OBJS)
	rm $(OUT).txt
