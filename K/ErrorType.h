#pragma once

#include <string>
class ErrorType
{

public:
	enum Type {
		NO_ERRORS = 0,
		LOOPING = 1,
		INCORRECT_CELL_TYPE = 2,
		PARSING_ERROR = 3
	};
	
	/// get string with comment for error (ErrorType::Type)
	const char * getComment(Type type);

private:
	ErrorType();
	static const char * const TypeComment[];


};
