all: lab21	lab21test

lab21test: bst_node.o lab_21_unit_test.o
	g++ -Wall -g -o lab21test bst_node.o lab_21_unit_test.o

lab21: bst_node.cpp lab_21_unit_test.cpp
	g++ -Wall -g -c bst_node.cpp
	g++ -Wall -g -c lab_21_unit_test.cpp