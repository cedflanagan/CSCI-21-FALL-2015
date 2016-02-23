all: lab9 lab9test

lab9test: lab_9.o lab_9_unit_test.o
	g++ -Wall -g -o lab9test lab_9.o lab_9_unit_test.o

lab9: lab_9.cpp lab_9_unit_test.cpp
	g++ -Wall -g -c lab_9.cpp
	g++ -Wall -g -c lab_9_unit_test.cpp