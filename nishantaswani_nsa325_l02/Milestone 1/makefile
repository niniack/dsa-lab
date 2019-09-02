#  File: makefile (milestone 2)
#  Name: Nishant Aswani
#  Instructor: Cristoforos Vasilatos
#  Course: Data Structures and Algorithms (ENGR-UH 3510) Fall 2019
#  Due: Sep 2 2019

PROG = lab2_milestone2
CC = g++
CPPFLAGS = -g -Wall

all: generate run

generate :
	@echo "Compiling object..."
	${CC} $(CPPFLAGS) -o $(PROG) *.cpp

run :
	@echo "Running compiled object..."
	./$(PROG)

clean:
	@echo "Cleaning up..."
	rm -f core $(PROG) $(OBJS)
