#include "easyfind.hpp"

#include <string>
// #include <array>
#include <vector>
#include <iostream>

using std::cout;
using std::endl;

int main()
{
	int arr[] = {0, 1, 2, 3};
	std::vector<int> vec(arr, arr + 4);
	std::string str("\4\5\6\7");

	cout << str;
	try
	{
		cout << *easyfind(vec, 0) << endl;
		cout << *easyfind(vec, 10) << endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "couldn't find value in vector" << endl;
		(void)e;
	}

	try
	{
		cout << static_cast<int>(*easyfind(str, 4)) << endl;
		cout << *easyfind(str, 30) << endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "couldn't find value in str" << endl;
		(void)e;
	}
}