all: lab22	lab22test

lab22test: lab_22.o lab_22_unit_test.o
	g++ -Wall -g -o lab22test lab_22.o lab_22_unit_test.o

lab22: lab_22.cpp lab_22_unit_test.cpp
	g++ -Wall -g -c lab_22.cpp
	g++ -Wall -g -c lab_22_unit_test.cpp