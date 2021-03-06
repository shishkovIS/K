#pragma once

#include <iostream>

using std::string ;

class ErrorType
{

public:
	enum Type {
		NO_ERRORS = 0,
		LOOPING = 1,
		INCORRECT_CELL_TYPE = 2,
		PARSING_ERROR = 3,
		INCORRECT_CELL_FORMAT = 4,
		DIV_BY_ZERO = 5
	};
	
	/// get string with comment for error (ErrorType::Type)
	static const string& get_comment(Type type);

private:
	ErrorType();
	static const string type_comment[];


};
