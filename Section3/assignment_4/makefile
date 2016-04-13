all: assignment4 assignment4exe

assignment4exe: dl_node.o dl_list.o musical_chairs.o
	g++ -Wall -g -o musical_chairs dl_node.o dl_list.o musical_chairs.o

assignment4: dl_node.cpp dl_list.cpp
	g++ -Wall -g -c dl_node.cpp
	g++ -Wall -g -c dl_list.cpp
	g++ -Wall -g -c musical_chairs.cpp