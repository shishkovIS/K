#include "Table.h"


void Table::read()
{
	// size reading
	read_size();

	// memory allocation
	table.resize(row);
	for (int row_index = 0; row_index < row; row_index++)
	{
		table[row_index].resize(col);
	}

	// read lines
	vector<char> buff;
	int t;
	for (int lineNumber = 0; lineNumber < row; lineNumber++)
	{
		for (int colNumber = 0; colNumber < col; colNumber++)
		{
			for(t = getchar();
			    t != '\t' && t != '\n' && t != EOF;
				t = getchar())
			{
				buff.push_back(t);
			}

			if ((t == '\n' || t == EOF) &&
				(colNumber != (col - 1))) // not last column
			{
				throw (string("Some cells are missing in the row "+std::to_string(lineNumber+1)));
			}

			buff.push_back('\0');

			table[lineNumber][colNumber].set_initial_value(buff.data());

			buff.clear();
		}

		if (t != '\n' && t != EOF) // if there are else cells on this row
		{
			throw (string("Wrong cell number in the row "+std::to_string(lineNumber+1)));
		}
		if (t == EOF &&
			lineNumber != (row - 1)) // not last row
		{
			throw (string("Some rows are missing"));
		}
	}
#ifdef CONSOLE_DEBUG
	if (t != EOF && (t = getchar()) != EOF && t != '\n') // there are else rows 
#else
	if (t != EOF && (t = getchar()) != EOF) // there are else rows 
#endif
	{
		throw (string("There are some excess rows"));
	}
}

void Table::calculate()
{
    for (auto &line : table)
		for (auto &cell : line)
			cell.compute();
}

void Table::write()
{
    for (auto &line : table)
	{
        bool is_first_cell = true;
		for (auto &cell : line)
		{
            if (!is_first_cell)
				cout << '\t';
            else
                is_first_cell = false;
			cout << cell.get_string();
		}
		cout << endl;
	}
}
vector<Cell>::iterator &
    Table::getCell(int row, int col)
{
	if (row >= 1 && row <= this->row &&
		col >= 0 && col < this->col)
		return (table.begin() + (row-1).begin() + col;
	return vector<Cell>::end();
}




void Table::read_size()
{
	const int buff_size = 128;
	char buff[buff_size];

	cin.getline(buff, buff_size);
	if (!cin.good())
	{
		throw (string("Error in input stream"));
	}

	string buff_str(buff);
	regex pieces_regex("([0-9]+) ([0-9]+)\0");
	std::match_results<std::string::const_iterator>  pieces_match;
	if (regex_match(buff_str, pieces_match, pieces_regex))
	{
		std::string piece1 = pieces_match[1].str();
		std::string piece2 = pieces_match[2].str();
		col = stoi(piece2);
		row = stoi(piece1);
		if ((col == 0) || (row == 0))
			throw (string("Error while parsing first string"));
		return;
	}
	
	throw (string("Error while parsing first string"));
}

