#pragma once
#include <vector>
#include <pair>
#include <string>

#include "ErrorType.h"
using namespace std;

class Expression_Manager
{
	
public: vector<pair<string, char>> operands;
		int result;
		ErrorType::Type error;

		bool compute();
		int get_value();

	Expression_Manager();
	~Expression_Manager();
};

