#include "ErrorType.h"

const char * const ErrorType::TypeComment[] = {
	"",						//NO_ERRORS
	"Looping",				//LOOPING
	"Incorrect_cell_type",	//INCORRECT_CELL_TYPE
	"Parsing error"			//PARSING_ERROR
};

const char * ErrorType::getComment(Type type)
{
	return TypeComment[type];
}
