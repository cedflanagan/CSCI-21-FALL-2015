all: Temperature lab10test

lab10test: temperature.o lab_10_unit_test.o
	g++ -Wall -g -o lab10test temperature.o lab_10_unit_test.o

Temperature: temperature.cpp lab_10_unit_test.cpp
	g++ -Wall -g -c temperature.cpp
	g++ -Wall -g -c lab_10_unit_test.cpp