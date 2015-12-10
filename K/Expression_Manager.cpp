#include "Expression_Manager.h"
#include <regex>
#include "Cell.h"
#include "Table.h"

Expression_Manager::Expression_Manager()
{
}


Expression_Manager::~Expression_Manager()
{
}

Expression_Manager::Expression_Manager(string expression)
{
	this->expression = expression;
}

bool Expression_Manager::split_expression()
{
	if (!check_expression())
		return false;

	string str = this->expression;
	std::size_t prev_pos = 0, pos;
	char current_delimiter;

	while ((pos = str.find_first_of("+-/*", prev_pos)) != std::string::npos)
	{
		if (pos > prev_pos)
		{
			current_delimiter = prev_pos == 0 ? '+' : str[prev_pos - 1];
			operands.push_back(make_pair(str.substr(prev_pos, pos - prev_pos), current_delimiter));
		}
		prev_pos = pos + 1;
	}
	if (prev_pos< str.length()) {
		char last_delimiter = prev_pos == 0 ? '+' : str[prev_pos - 1];
		operands.push_back(make_pair(str.substr(prev_pos, std::string::npos), last_delimiter));
	}
	return true;
}

bool Expression_Manager::check_expression()
{
	regex expression_regex("^((((0|[1-9][0-9]*)|([A-Z][1-9]))(\+|-|\*|\/))*((0|[1-9][0-9]*)|([A-Z][1-9])))$");
	return regex_match(this->expression, expression_regex);
}
bool Expression_Manager::compute()
{
	if (!split_expression())
		return false;

	int expression_value = 0;

	int vector_size = this->operands.size();
	for (int i = 0; i<vector_size; i++)
	{
		
		if (this->error == ErrorType::NO_ERRORS)
			expression_value = get_signed_operand(expression_value, i);
		else break;

	}
	
	if (this->error != ErrorType::NO_ERRORS)
		return false;
	else return true;
	
	//return false if cant calculate expression
}


int Expression_Manager::get_signed_operand(int old_value, int index)
{
	int current_value = 0;

	if (check_number(operands[index].first))
		current_value = stoi(operands[index].first);
	else if (check_cell(operands[index].first))
		current_value = get_cell_value(operands[index].first);


	switch (operands[index].second)
	{
	case '+':
		return old_value += current_value;
		break;
	case '-':
		return old_value -= current_value;
		break;
	case '*':
		return old_value *= current_value;
		break;
	case '/':
		return old_value /= current_value;
		break;
	}

}

int Expression_Manager::get_cell_value(string operand)
{
	Cell* cell;
	int row = get_row(operand);
	int col = get_col(operand);
	
	Table& table = Table::Instance();
	cell = table.getCell(row, col);
	if (cell == NULL)
	{
		this->error = ErrorType::PARSING_ERROR;
		return 0;
	}

	if (cell->get_type() == Cell::UNKNOWN)
		cell->compute();
	if ((cell->get_type() == Cell::ERROR) || (cell->get_type() == Cell::STRING) || (cell->get_type() == Cell::STRING))
	{
		//kmnhouih
		this->error = ErrorType::PARSING_ERROR;
		return 0;
	} 

	return cell->get_int();

}

ErrorType::Type Expression_Manager::get_error()
{
	return error;
}
bool Expression_Manager::check_cell(string operand)
{
	regex cell("^([A-Z][1-9])$");
	return regex_match(operand, cell);

}
bool Expression_Manager::check_number(string operand)
{
	regex number("^(0|[1-9][0-9]*)$");
	return regex_match(operand, number);
}
int Expression_Manager::get_value()
{
	return this->result;
	//return value if expression is calculated
}
int Expression_Manager::get_row(string operand)
{
	return static_cast<int>(operand[1]) - 48;
}

int Expression_Manager::get_col(string operand)
{
	return static_cast<int>(operand[0]) - 64;
}
