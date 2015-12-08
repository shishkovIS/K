#pragma once
#include <vector>
#include <pair>
#include <string>

using namespace std;

class Expression_Manager
{
	
public: vector<pair<string, char>> operands;
		int result;
		int error; // must be error type

		bool compute();
		int get_value();

	Expression_Manager();
	~Expression_Manager();
};

