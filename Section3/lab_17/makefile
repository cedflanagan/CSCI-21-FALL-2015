all: lab17 lab17test

lab17test: sl_node.o sl_list.o lab_17_unit_test.o
	g++ -Wall -g -o lab17test sl_node.o sl_list.o lab_17_unit_test.o

lab17: sl_node.cpp sl_list.cpp
	g++ -Wall -g -c sl_node.cpp
	g++ -Wall -g -c sl_list.cpp