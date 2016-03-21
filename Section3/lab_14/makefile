all: lab14 lab14test

lab14test: lab_14.o lab_14_unit_test.o
	g++ -Wall -g -o lab14test lab_14.o lab_14_unit_test.o

lab14: lab_14.cpp
	g++ -Wall -g -c lab_14.cpp
	g++ -Wall -g -c lab_14_unit_test.cpp