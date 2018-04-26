#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstdint> //What does this and below function do?
#include <cstdlib>
#include <array>
using namespace std;

#define cache_size1024		1024
#define cach_size4096		4096
#define cache_size65536		65536
#define cache_size131072	131072

#define block_size8			8
#define block_size16		16
#define block_size32		32
#define block_size128		128

#define tag_mask			4294963200	// Mem_Addr[31:12]- 20bits
#define index_mask			4092		// Mem_Addr[11:2]- 10bits
#define offset_mask			3			// Mem_Addr[1:0]- 2 bits

typedef struct {
	string command = "Bad";
	int hexadecimal = 7;
} Memory;

void simulate(string command, int hexadecimal) 
{
	typedef enum {d_map, w2, w4, full} placement; //Double check syntax

	bool policy = true; //True = Write-Back, False = Write-Through

	int block_count = 0;
	int words_per_block = 0;
	int totB_Mem2Cache, totB_Cache2Mem = 0;

	//CACHES SIZE 1024
}

void simulate2(vector<Memory> memory)
{
	typedef enum { d_map, w2, w4, full } placement; //Double check syntax

	bool policy = true; //True = Write-Back, False = Write-Through

	int block_count = 0;
	int words_per_block = 0;
	int totB_Mem2Cache, totB_Cache2Mem = 0;

	int tag = 0;
	int index = 0;
	int offset = 0;

	array<bool, 128> valid; //May need to make size larger!!! Arre a
	valid.fill(false);		//Fills are


	//SECTION A.
	for (int i = 0; i < 128; i++)
	{
		tag = memory.at(i).hexadecimal & tag_mask;
		index = memory.at(i).hexadecimal & index_mask;
		offset = memory.at(i).hexadecimal & offset_mask;

		valid[index] = true;


		//Read from Cache??
		if (valid[index] == false)
		{

			i--; //???
		}


	}

	//Clear Array
	valid.fill(false);



}

int main(int argc, char *argv[])
{
	vector<string> arguments;

	if (argc == 0)
	{
		cout << "EXIT_FAILURE" << endl;
		return EXIT_FAILURE;
	}
	else
	{
		for (int i = 0; i < 3; i++)
		{
			arguments.push_back(argv[i]);
		}
		cout << "Executable File: " << arguments[0] << endl;
		cout << "Input File: " << arguments[1] << endl;
		cout << "Output File: " << arguments[2] << endl;

		string line;
		ifstream input_file;
		string command;
		string hexadecimal;
		//char char_0;
		//char char_x;
		vector<Memory> container;

		input_file.open(arguments[1], ifstream::in);
		int i = 0; //Line index. For debugging
		while (getline(input_file, line))
		{
			istringstream iss(line);
			unsigned int hex2dec;
			stringstream ss;
			Memory temp;
			iss >> command >> hexadecimal;
			//iss >> command >> char_0 >> char_x >> hexadecimal;
			cout << i << ". Line Read: " << line << endl;								//For Debugging
			cout << "Command: " << command << "\tHex Value: " << hexadecimal << endl;	//For Debugging

			//Convert Hex String to Hex value?


			//Converts Hex String to Decimal
			ss << std::hex << hexadecimal;
			ss >> hex2dec;
			cout << hex2dec << endl;

			//Stores values in a vector
			//container[i].command = command;
			//container[i].hexadecimal = hex2dec;
			temp.command = command;
			temp.hexadecimal = hex2dec;
			container.push_back(temp);

			//cout << "Temp: " << container.at(i).command << "\t" << container.at(i).hexadecimal << endl; //For Debugging
			i++;
		}
	}		
    return 0;
}