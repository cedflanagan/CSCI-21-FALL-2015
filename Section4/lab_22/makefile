all: lab22	lab22test

lab22test: bst_node.o bs_tree.o lab_22_unit_test.o
	g++ -Wall -g -o lab22test bst_node.o bs_tree.o lab_22_unit_test.o

lab22: bst_node.cpp bs_tree.cpp lab_22_unit_test.cpp
	g++ -Wall -g -c bst_node.cpp
	g++ -Wall -g -c bs_tree.cpp
	g++ -Wall -g -c lab_22_unit_test.cpp