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
	//ughugh
	ErrorType::Type get_error();
	int get_value();
	
	Expression_Manager();
	Expression_Manager(string expression);
	~Expression_Manager();
private:

	ErrorType::Type error;
	vector<pair<string, char>> operands;
	int result;
	string expression;

	bool check_expression();
	bool split_expression();
	
	int get_signed_operand(int old_value,int index);
	bool check_number(string operand);
	bool check_cell(string operand);
	int get_row(string operand);
	int get_col(string operand);
	int get_cell_value(string operand);
};

