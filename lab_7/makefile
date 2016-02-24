all: lab7 lab8 lab7test  lab8test
	
lab8test: lab_7.o lab_8_unit_test.o
	g++ -Wall -g -o lab8test lab_7.o lab_8_unit_test.o

lab8: lab_8_unit_test.cpp
	g++ -Wall -g -c lab_8_unit_test.cpp

lab7test: lab_7.o lab_7_unit_test.o
	g++ -Wall -g -o lab7test lab_7.o lab_7_unit_test.o
	
lab7: lab_7.cpp lab_7_unit_test.cpp
	g++ -Wall -g -c lab_7.cpp
	g++ -Wall -g -c lab_7_unit_test.cpp
