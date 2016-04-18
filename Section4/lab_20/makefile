all: lab20	lab20test

lab20test: lab_20.o lab_20_unit_test.o
	g++ -Wall -g -o lab20test lab_20.o lab_20_unit_test.o

lab20: lab_20.cpp lab_20_unit_test.cpp
	g++ -Wall -g -c lab_20.cpp
	g++ -Wall -g -c lab_20_unit_test.cpp