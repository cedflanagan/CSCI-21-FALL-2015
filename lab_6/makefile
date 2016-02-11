all: lab6 lab6test

lab6test: lab_6.o lab_6_unit_test.o
	g++ -Wall -g -o lab6test lab_6.o lab_6_unit_test.o

lab6: lab_6.cpp lab_6_unit_test.cpp
	g++ -Wall -g -c lab_6.cpp
	g++ -Wall -g -c lab_6_unit_test.cpp