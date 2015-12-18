#pragma once
#include <vector>
#include <string>
#include <regex>

#include "ErrorType.h"
#include "Expression_Manager.h"
using namespace std;
class Cell
{
public: 
	enum Type {
		UNKNOWN,
		ERROR,
		NUMBER,
		STRING,
		EMPTY
	};

	Cell();
	~Cell();

	// Compute cell
	void compute();

	Type get_type(); 
	ErrorType::Type get_error();

	// Get cell value
	const string& get_string() const;
	// Get cell value
	int get_int();
	
	// Initialize cell
	void set_initial_value(const char * source);

private:
	// Source cell value
	std::string source;
	// Result cell value (string)
	string result_string;
	// Result cell value (number)
	int result_int;
	
	Type cell_type;
	ErrorType::Type error_type;

	bool processing;
};

