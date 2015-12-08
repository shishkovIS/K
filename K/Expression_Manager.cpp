#include "Expression_Manager.h"



Expression_Manager::Expression_Manager()
{
}


Expression_Manager::~Expression_Manager()
{
}

bool Expression_Manager::compute()
{
	throw "Not implemented";
	//return false if cant calculate expression
}

ErrorType::Type Expression_Manager::get_error()
{
	return error;
}

int Expression_Manager::get_value()
{
	throw "Not implemented";
	//return value if expression is calculated
}
