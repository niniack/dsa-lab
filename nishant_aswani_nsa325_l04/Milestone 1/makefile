#  File: makefile
#  Name: Nishant Aswani
#  Instructor: Cristoforos Vasilatos
#  Assignment: Prelab 4
#  Course: Data Structures and Algorithms (ENGR-UH 3510) Fall 2019
#  Due: Sep 16 2019

PROG = lab4_m1
OUT = lab4_m1_output
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
