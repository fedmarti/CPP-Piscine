#include "BitcoinExchange.hpp"
#include <iostream>

using std::cout;
using std::endl;


int main ( int argc, char **argv )
{
	if (argc < 2)
		return (0);
	// (void)argv;
	/*
	string arg = argv[1];
	arg = arg.substr(0, arg.find(","));
	arg = arg.substr(0, arg.find("|"));
	string date;
	
	if (parse_date(const_cast<char *>(arg.c_str()), date))
		cout << date;
	else 
		cout << "error";
	cout << endl;
	*/

	if (!BitcoinExchange::init())
		return (1);
	BitcoinExchange::read(argv[1]);
	
	return (0);
}