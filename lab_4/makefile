all: lab4 lab4test

lab4test: lab_4.o lab_4_unit_test.o
	g++ -Wall -g -o lab4test lab_4.o lab_4_unit_test.o

lab4: lab_4.cpp lab_4_unit_test.cpp
	g++ -Wall -g -c lab_4.cpp
	g++ -Wall -g -c lab_4_unit_test.cpp