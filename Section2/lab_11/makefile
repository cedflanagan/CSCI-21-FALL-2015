all: Money lab11test

lab11test: money.o lab_11_unit_test.o
	g++ -Wall -g -o lab11test money.o lab_11_unit_test.o

Money: money.cpp lab_11_unit_test.cpp
	g++ -Wall -g -c money.cpp
	g++ -Wall -g -c lab_11_unit_test.cpp