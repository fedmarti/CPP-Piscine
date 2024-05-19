#include "PmergeMe.hpp"
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <string>
#include <climits>
using	std::cout;
using	std::endl;

void	_printn(int n)
{
	cout << n << " ";
}

static bool is_int(char *str)
{
	if (!str)
		return (false);

	while(isspace(*str))
		str++;
	
	if (*str == '+' || *str == '-')
		str++;

	if (!*str)
		return (false); 
	
	while (*str)
	{
		if (!isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}

static int _parse(char *str) throw (std::string)
{
	if (!is_int(str))
		throw (std::string("Not an integer"));

	long long long_n = atoll(str);

	if (long_n < INT_MIN || long_n > INT_MAX)
		throw (std::string("Outside integer range"));
	
	if (long_n < 0)
		throw (std::string("Negative number"));
	return static_cast<int>(long_n);
}

int *get_input(int argc, char **argv, const int &LEN)
{
	std::string arg1 = argv[1];
	bool rnd = (arg1 == "rnd" || arg1 == "Rnd" || arg1 == "RND");
	int min_range = 0, max_range = 30;

	int *arr;

	if (rnd)
	{
		srand(time(NULL));
		const_cast<int &>(LEN) = (argc == 2)? rand() % 20 : atoi(argv[2]);
		if (LEN <= 0)
			return (NULL);
		if (argc > 3)
		{
			max_range = atoi(argv[3]);
		}
		if (argc > 4)
		{
			min_range = atoi(argv[4]);
		}
		if (min_range > max_range)
			std::swap(max_range, min_range);
		else if (min_range == max_range)
		{
			if (max_range == INT_MAX)
				min_range--;
			else
				max_range++;
		}
	}
	arr = new int[LEN];
	if (!arr)
		return (NULL);

	try
	{
		for (int i = 0; i < LEN; i++)
			arr[i] = (rnd)? rand() % (max_range - min_range + 1) + min_range : _parse(argv[i + 1]);
	}
	catch (std::string str)
	{
		delete [] arr;
		cout << str << endl;
		arr = NULL;
	}
	return (arr);
}

int main(int argc, char **argv)
{
	if (argc <= 1)
	{
		cout << "Empty list" << endl;
		if (argc == 0)
			return (1);
		cout << "usage:\n\tlist mode: " << argv[0] << " 223 44 12 32323 51...\n" <<
		"\trandom mode: " << argv[0] << " rnd [length] [max range] [min range]... (default rand 0-19, 0, 30)" << endl;
		return (1);
	}

	const int LEN = argc - 1;
	int *arr = get_input(argc, argv, LEN);
	if (!arr)
	{
		cout << "Failed alloc" << endl;
		return (1);
	}
	vector<int> v(LEN);
	deque<int> d(LEN);

	for (int i = 0; i < LEN; i++)
	{
		v.at(i) = arr[i];
		d.at(i) = arr[i];
	}
	cout << "Before: ";
	std::for_each(v.begin(), v.end(), _printn);
	cout << endl;

	long time_to_sort = PmergeMe::mergesort(v);
	
	cout << "After: ";
	std::for_each(v.begin(), v.end(), _printn);
	cout << endl;

	cout << "Time to process of	" << v.size() << " elements with std::vector : " << time_to_sort / (CLOCKS_PER_SEC / 100000.0) << "us" << endl;
	// cout << "Time to process of	" << argc - 1 << " elements with std::vector : " << time_to_sort / (CLOCKS_PER_SEC / 100000) << endl;
	
	time_to_sort = PmergeMe::mergesort(d);
	cout << "Time to process of	" << d.size() << " elements with std::deque : " << time_to_sort / (CLOCKS_PER_SEC / 100000.0) << "us" << endl;
	delete [] arr;
	return (0);
}
//use vector and lists with iterators