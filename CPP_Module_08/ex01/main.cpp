#include "Span.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

int main()
{
	Span	s1(10);
	Span	s2(0);

	try
	{
		s1.addNumber(99);
		s1.addNumber(2);
		bool use_vector = true;
		if (use_vector)
		{
			std::vector<int> v;
			for (int i = 2; i < 10; i++)
				v.push_back(i);
			s1.addRange(v.begin(), v.end());
		}
		else
		{
			int  v2[] = {2, 3, 100, 5, 6, 7, 8, 9};
			s1.addRange(v2, v2 + sizeof(v2));

		}
		
		s1.addNumber(69);
		s2.addNumber(21);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "span 1: " << s1 << std::endl;
	std::cout << "span 2: " << s2 << std::endl;
	
	try
	{
		std::cout << "s1: \n\tshortest span: " << s1.shortestSpan() << "\n\tlongest span:" << s1.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	
	}
	
	try
	{
		std::cout << "s2:\n\tshortest span: " << s2.shortestSpan() << "\n\tlongest span:" << s2.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	
	}

	srand(time(0));

	Span s3(rand() % 7 + 3);
	try 
	{

	for (unsigned i = 0; i < s3.getN(); i++)
	{
		int n = rand() % 201 - 100;
		if (rand() % 10 < 7)
		{
			s3.addNumber(n);
		}
		else
		{
			s3.addRange(n , n + rand() % (s3.getN() - i));
		}

		try
		{
			std::cout << "s3: " << s3 << "\n\tshortest span: " << s3.shortestSpan() << "\n\tlongest span:" << s3.longestSpan() << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	}
	catch (std::exception &e)
	{
		(void)e;
	}
	
}