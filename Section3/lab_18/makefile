all: lab18 lab18test

lab18test: sl_node.o sl_list.o lab_18_unit_test.o
	g++ -Wall -g -o lab18test sl_node.o sl_list.o lab_18_unit_test.o

lab18: sl_node.cpp sl_list.cpp
	g++ -Wall -g -c sl_node.cpp
	g++ -Wall -g -c sl_list.cpp