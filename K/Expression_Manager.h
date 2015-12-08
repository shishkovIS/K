#pragma once

#include <utility> // pair
#include <vector>
#include <string>

#include "ErrorType.h"
using namespace std;

class Expression_Manager
{
	
public: 
	bool compute();
	ErrorType::Type get_error();
	int get_value();
	
	Expression_Manager();
	~Expression_Manager();
private:

	ErrorType::Type error;
	vector<pair<string, char>> operands;
	int result;
};

