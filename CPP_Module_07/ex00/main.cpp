#include <iostream>
#include "whatever.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	int a, b;

	cout << "a:\n";
	cin >> a;
	cout << "b:\n";
	cin >> b;

	cout << "a: " << a << " b: " << b << endl;

	cout << "min: " << min(a, b) << endl;
	cout << "max: " << max(a, b) << endl;
	cout << "swap" << endl;
	swap(a, b);
	cout << "a: " << a << " b: " << b << endl;
}