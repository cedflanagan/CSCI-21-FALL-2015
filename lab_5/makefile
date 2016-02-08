all: lab4 lab5test

lab5test: lab_5.o lab_5_unit_test.o
	g++ -Wall -g -o lab5test lab_5.o lab_5_unit_test.o

lab4: lab_5.cpp lab_5_unit_test.cpp
	g++ -Wall -g -c lab_5.cpp
	g++ -Wall -g -c lab_5_unit_test.cpp