all: lab24	lab24test

lab24test: bst_node.o bs_tree.o lab_24_unit_test.o
	g++ -Wall -g -o lab24test bst_node.o bs_tree.o lab_24_unit_test.o

lab24: bst_node.cpp bs_tree.cpp lab_24_unit_test.cpp
	g++ -Wall -g -c bst_node.cpp
	g++ -Wall -g -c bs_tree.cpp
	g++ -Wall -g -c lab_24_unit_test.cpp