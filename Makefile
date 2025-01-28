# Harshiv Mistry
# 10-29-24

CFLAGS = -Wall -g -std=c++17

all: compile run

compile: 
	g++ -o haunted_house $(CFLAGS) *.cpp
run: 
	./haunted_house

vim: 
	vim -p *.cpp *.h

