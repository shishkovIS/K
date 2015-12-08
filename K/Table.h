#include "Cell.h"
#include <vector>

using namespace std;
class Table //Singleton
{
public: int row, col; //table size
		vector<vector<Cell>> table;
 	static Table & Instance()
	{
		// It **is** thread-safe in C++11.
		static Table myInstance;
	
		return myInstance;
	}

	// delete copy and move constructors and assign operators
	Table(Table const&) = delete;             // Copy construct
	Table(Table&&) = delete;                  // Move construct
	Table& operator=(Table const&) = delete;  // Copy assign
	Table& operator=(Table &&) = delete;      // Move assign

													  // Any other public methods
	void read();
	void calculate();
	void write();

	Cell* getCell(int row, int col);
	
protected:
	Table()
	{
		// Constructor code goes here.
	}

	~Table()
	{
		// Destructor code goes here.
	}

	// And any other protected methods.
};