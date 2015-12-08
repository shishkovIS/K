#pragma once

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
	static const char * get_comment(Type type);

private:
	ErrorType();
	static const char * const type_comment[];


};
