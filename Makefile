all: dfa.hpp status.hpp main.cpp dfa.cpp status.cpp
	g++ -std=c++11 main.cpp dfa.cpp status.cpp -o test