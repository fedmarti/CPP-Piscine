#include "easyfind.hpp"

#include <string>
// #include <array>
#include <vector>
#include <iostream>
#include <list>

using std::cout;
using std::endl;

void	_print(int n)
{
	cout << n << " ";
}

template <typename T, typename U>
static void	_test( T container, U start, const U &end )
{
	cout << "testing: { ";
	std::for_each(container.begin(), container.end(), _print);
	cout << "}" << endl;
	while (start < end)
	{
		cout << "searching for " << *start << ".\n";
		typename T::iterator i = easyfind(container, *start);
		if (i != container.end())
		{
			cout << "Found at a distance of " << std::distance(container.begin(), i);
		}
		else
		{
			cout << "But couldn't find it";
		}
		cout << endl;
		start++;
	}
}

int main()
{
	int arr[] = {0, 1, 2, 3};
	std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(*arr));
	std::string str("\4\5\6\7");

	int list_arr[] = {8, 9, 10, 11};
	std::list<int> lst(list_arr, list_arr + sizeof(list_arr) / sizeof(*list_arr));
	cout << str;
	int test_arr[] = {0, 10, 5};
	_test(vec, test_arr, test_arr + sizeof(test_arr) / sizeof(*test_arr));
	cout << endl;
	_test(str, test_arr, test_arr + sizeof(test_arr) / sizeof(*test_arr));
	cout << endl;
	_test(lst, test_arr, test_arr + sizeof(test_arr) / sizeof(*test_arr));

}