#include "ErrorType.h"

const char * const ErrorType::type_comment[] = {
	"",						//NO_ERRORS
	"Looping",				//LOOPING
	"Incorrect_cell_type",	//INCORRECT_CELL_TYPE
	"Parsing error"			//PARSING_ERROR
};


const char * ErrorType::get_comment(Type type)
{
	return type_comment[type];
}
