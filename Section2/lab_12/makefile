all: Item lab12test

lab12test: item.o food_item.o magic_item.o lab_12_unit_test.o
	g++ -Wall -g -o lab12test item.o food_item.o magic_item.o lab_12_unit_test.o

Item: item.cpp food_item.cpp magic_item.cpp
	g++ -Wall -g -c item.cpp
	g++ -Wall -g -c food_item.cpp
	g++ -Wall -g -c magic_item.cpp
	g++ -Wall -g -c lab_12_unit_test.cpp