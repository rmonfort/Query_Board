#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::getline;
using std::istringstream;

struct Query_Board
{
	int board[256][256];

	void InitBoard();
	void SetRow(const int &i, const int &x);
	void SetCol(const int &j, const int &x);
	void QueryRow(const int &i);
	void QueryCol(const int &j);

};

// Initialize all the values in the board to 0
void Query_Board::InitBoard()
{
	for (size_t i = 0; i < 256; i++)
	{
		for (size_t j = 0; j < 256; j++)
		{
			board[i][j] = 0;
		}
	}
}

// Set all the values in row i to x
void Query_Board::SetRow(const int &i, const int &x)
{
	for (size_t j = 0; j < 256; j++)
	{
		board[i][j] = x;
	}
}

// Set all the value in col j to x
void Query_Board::SetCol(const int &j, const int &x)
{
	for (size_t i = 0; i < 256; i++)
	{
		board[i][j] = x;
	}
}

// Print the sum of all the values in row i
void Query_Board::QueryRow(const int &i)
{
	int sum = 0;
	for (size_t j = 0; j < 256; j++)
	{
		sum += board[i][j];
	}
	cout << sum << endl;
}

// Print the sum of all the values in col j
void Query_Board::QueryCol(const int &j)
{
	int sum = 0;
	for (size_t i = 0; i < 256; i++)
	{
		sum += board[i][j];
	}
	cout << sum << endl;
}

int main(int argc, char *argv[])
{
	string input_file;

	// Check first argument if it exists for input file, otherwise ask user
	if (argc > 1)
	{
		input_file = argv[1];
	}
	else
	{
		cout << "Please enter the path to your input file: " << endl;
		cin >> input_file;
	}

	// Open input file and check if successfully opened
	ifstream ifs(input_file);
	if (!ifs)
	{
		cout << "Failed to open input file." << endl;
		return 1;
	}

	// Create Query Board and initialize all the values to 0
	Query_Board my_board;
	my_board.InitBoard();

	string line, word;
	int arg1 = 0, arg2 = 0;

	// Cycle through input file, convert each line to its indicated function, and run it
	while (getline(ifs, line))
	{
		
		istringstream iss(line);
		iss >> word;
		if (word == "SetRow")
		{
			iss >> arg1;
			iss >> arg2;
			my_board.SetRow(arg1, arg2);
		}
		else if (word == "SetCol")
		{
			iss >> arg1;
			iss >> arg2;
			my_board.SetCol(arg1, arg2);
		}
		else if (word == "QueryRow")
		{
			iss >> arg1;
			my_board.QueryRow(arg1);
		}
		else if (word == "QueryCol")
		{
			iss >> arg1;
			my_board.QueryCol(arg1);
		}
	}

	return 0;
}