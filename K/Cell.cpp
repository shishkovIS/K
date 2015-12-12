#include "Cell.h"


Cell::Cell()
{
	this->cell_type = Cell::UNKNOWN;
	this->processing = false;
}

Cell::~Cell()
{

}
void Cell::compute()
{
	
	const regex is_number("^[0-9]+$");

	if (this->cell_type != Cell::UNKNOWN)
		return;
	if (this->processing)
	{
		this->cell_type = Cell::ERROR;
		this->error_type = ErrorType::LOOPING;
		return;
	}
	if (this->source.empty())
	{
		this->cell_type = Cell::EMPTY;
	}
	else if (this->source[0] == '\'')
	{
		this->cell_type = Cell::STRING;
		this->result_string = this->source.substr(1);
	}
	else if (this->source[0] == '=')
	{
		processing = true;
		Expression_Manager em(this->source.substr(1));
		if (!em.compute())
		{
			this->cell_type = Cell::ERROR;
			this->error_type = em.get_error();
		}
		else
		{
			this->cell_type = Cell::NUMBER;
			this->result_int = em.get_value();
			this->result_string = to_string(this->result_int);
		}
		processing = false;
	}
	else if (regex_match(this->source, is_number))
	{
		this->cell_type = Cell::NUMBER;
		this->result_int = stoi(this->source);
		this->result_string = this->source;
	}
	else
	{
		this->cell_type = Cell::ERROR;
		this->error_type = ErrorType::INCORRECT_CELL_FORMAT;
	}

}
Cell::Type Cell::get_type()
{
	return cell_type;
}

ErrorType::Type Cell::get_error()
{
	return this->error_type;
}

int Cell::get_int()
{
	if (cell_type == Cell::NUMBER)
		return this->result_int;

	throw (string("ERROR: This cell is not number"));
}

const string Cell::get_string()
{
	if (cell_type == Cell::ERROR)
	{
#ifdef TEST_MODE
		return "#";
#else
		return ErrorType::get_comment(error_type);
#endif
	}
	else if (cell_type != Cell::UNKNOWN)
	{
		return this->result_string;
	}
	else
	{
		throw (string("ERROR: This cell has not string result"));
	}
}

void Cell::set_initial_value(const char * source)
{
	this->source = source;
	cout << this->source.size() << endl;
}