#include "PmergeMe.hpp"
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using	std::cout;
using	std::endl;

void	_printn(int n)
{
	cout << n << " ";
}

int main()
{
	const int LEN = 10;
	int arr[LEN];

	srand(time(NULL));
	for (int i = 0; i < LEN; i++)
	{
		arr[i] = rand() % LEN;
	}
	vector<int> v(sizeof(arr) / sizeof(*arr));
	deque<int> d(sizeof(arr) / sizeof(*arr));

	for (unsigned long i = 0; i < sizeof(arr) / sizeof(*arr); i++)
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

	return (0);
}
//use vector and lists with iterators