#include "ErrorType.h"

const string ErrorType::type_comment[] = {
	"",							//NO_ERRORS
	"#Looping",					//LOOPING
	"#Incorrect_cell_type",		//INCORRECT_CELL_TYPE
	"#Parsing_error",			//PARSING_ERROR
	"#Incorrect_cell_format",	//INCORRECT_CELL_FORMAT
	"#Division_by_zero"			//DIV_BY_ZERO
};


const string& ErrorType::get_comment(Type type)
{
	return type_comment[type];
}
