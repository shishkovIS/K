// K.cpp: ���������� ����� ����� ��� ����������� ����������.
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
	return 0;
}

