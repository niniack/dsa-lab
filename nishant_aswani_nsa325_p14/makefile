#  File: makefile
#  Name: Nishant Aswani
#  Instructor: Cristoforos Vasilatos
#  Assignment: Lab 12
#  Course: Data Structures and Algorithms (ENGR-UH 3510) Fall 2019
#  Due: Nov 18 2019

PROG = prelab14
OUT = prelab14_output
CC = g++
CPPFLAGS = -g -Wall

all: generate run

generate :
	@echo "Compiling object..."
	${CC} $(CPPFLAGS) -o $(PROG) *.cpp

run :
	@echo "Running object in place...\n"
	./$(PROG)

write :
	@echo "Running object and saving text..."
	./$(PROG) -> $(OUT).txt

clean:
	@echo "Cleaning up..."
	rm -f core $(PROG) $(OBJS)
	# rm $(OUT).txt
