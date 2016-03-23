all: sl_node lab15test

lab15test: sl_node.o lab_15_unit_test.o
	g++ -Wall -g -o lab15test sl_node.o lab_15_unit_test.o

sl_node: sl_node.cpp lab_15_unit_test.cpp
	g++ -Wall -g -c sl_node.cpp
	g++ -Wall -g -c lab_15_unit_test.cpp