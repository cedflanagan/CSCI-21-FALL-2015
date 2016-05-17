all: lab27	lab27test

lab27test: lab_27.o lab_27_unit_test.o
	g++ -Wall -g -o lab27test lab_27.o lab_27_unit_test.o

lab27: lab_27.cpp lab_27_unit_test.cpp
	g++ -Wall -g -c lab_27.cpp
	g++ -Wall -g -c lab_27_unit_test.cpp