#include "Array.hpp"
#include <iostream>

template <typename T>
void print_arr(Array<T> arr)
{
	for (long i = 0; i < arr.size(); i++)
		std::cout << arr[i] << " ";
}

template class Array<int>;
template class Array<float>;

int main()
{
	Array<int>arr1;
	Array<float>arr2(10);

	for (long i = 0; i < arr2.size(); i++)
	{
		std::cout << "arr[" << i << "] = " << arr2[i] << std::endl;
		arr2[i] = i * 5;
	}
	Array<float>arr3 = arr2;
	print_arr(arr3);
}