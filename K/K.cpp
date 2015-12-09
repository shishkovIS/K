// K.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Table.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	Table& table = Table::Instance();
	try
	{
		table.read();
		table.calculate();
		table.write();
	}
	catch (string exception)
	{
		cout << exception;
	}
#ifdef CONSOLE_DEBUG
	cin.get();
#endif
	return 0;
}

