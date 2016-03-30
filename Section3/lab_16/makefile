all: lab16 lab16test

lab16test: sl_node.o sl_list.o lab_16_unit_test.o
	g++ -Wall -g -o lab16test sl_node.o sl_list.o lab_16_unit_test.o

lab16: sl_node.cpp sl_list.cpp
	g++ -Wall -g -c sl_node.cpp
	g++ -Wall -g -c sl_list.cpp