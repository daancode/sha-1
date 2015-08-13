#Makefile
all: main

main: 
	$(CXX) -pthread -std=c++11 -Wall -Wextra -c -o SHA1.o ../source/SHA1.cpp
	$(CXX) -pthread -std=c++11 -Wall -Wextra -o run.app SHA1.o run.cpp