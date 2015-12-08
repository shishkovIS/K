#pragma once
#include <vector>
#include <string>

using namespace std;
class Cell
{
public: enum type {
	UNKNOWN,
	ERROR,
	NUMBER,
	STRING,
	EMPTY
};
		std::string source;
		string result;
		int result;
		bool processing;
		int error_type; // структура ошибки

	Cell();
	~Cell();

	void compute();
	type get_type(); 
	int get_int();
	string get_string();

	void set_initial_value();
};

