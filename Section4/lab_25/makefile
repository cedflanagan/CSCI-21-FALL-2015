all: lab25	lab25test

lab25test: bst_node.o bs_tree.o lab_25_unit_test.o
	g++ -Wall -g -o lab25test bst_node.o bs_tree.o lab_25_unit_test.o

lab25: bst_node.cpp bs_tree.cpp lab_25_unit_test.cpp
	g++ -Wall -g -c bst_node.cpp
	g++ -Wall -g -c bs_tree.cpp
	g++ -Wall -g -c lab_25_unit_test.cpp