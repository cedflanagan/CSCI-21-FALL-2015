all: assignment3 assign3test

assign3test: assignment_3.o assign_3_unit_test.o
	g++ -Wall -g -o assign3test assignment_3.o assign_3_unit_test.o

assignment3: assignment_3.cpp assign_3_unit_test.cpp
	g++ -Wall -g -c assignment_3.cpp
	g++ -Wall -g -c assign_3_unit_test.cpp