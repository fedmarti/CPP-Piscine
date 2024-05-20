#include "RPN.hpp"
#include <iostream>

using std::cout;
using std::endl;


int main(int argc, char **argv)
{
	if (argc != 2)
	{
		cout << "Error\n";
		return (1);
	}
try
{
	int result = RPN::execute(argv[1]);
	cout << result << endl;
}
catch (RPN::GenericError &err)
{
	cout << err.what() << endl;
	return (1);
}
}