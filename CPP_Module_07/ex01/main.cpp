#include "iter.h"

int main()
{
	int arr[] = {0, 1, 2, 3, 4, 5};

	iter(arr, sizeof(arr) / sizeof(*arr), print<int>);
}