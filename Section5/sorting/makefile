all: sorting	lab15test

lab15test: sorting.o lab_15_unit_test.o
	g++ -Wall -g -o lab15test sorting.o lab_15_unit_test.o

sorting: sorting.cpp lab_15_unit_test.cpp
	g++ -Wall -g -c sorting.cpp
	g++ -Wall -g -c lab_15_unit_test.cpp