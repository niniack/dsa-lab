#  File: makefile
#  Name: Nishant Aswani
#  Instructor: Cristoforos Vasilatos
#  Assignment: Prelab 4
#  Course: Data Structures and Algorithms (ENGR-UH 3510) Fall 2019
#  Due: Sep 16 2019

PROG = prelab5
OUT = prelab5_output
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
	# rm $(OUT).txt
