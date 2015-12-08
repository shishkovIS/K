#include "Cell.h"


Cell::Cell()
{

}

Cell::~Cell()
{

}
void Cell::compute()
{
	
}
Cell::Type Cell::get_type()
{
	return cell_type;
}

int Cell::get_int()
{
	throw "Not implemented";
}
const string Cell::get_string()
{
	throw "Not implemented";
}

void Cell::set_initial_value(const char * source)
{
	this->source = source;
}