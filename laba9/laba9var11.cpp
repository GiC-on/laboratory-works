// Лабораторная работа 9 вариант 11
// Чупов Максим ЭиН-2 1к.

#include <iostream>

double func(double x, unsigned int n)
{
	if(n == 0) return 1;
	else if(n % 2 == 0)
	{
		double y = func(x, n/2);
		return y*y;
	}
	else return (x * func(x, n-1));
}

int main()
{
	double x;
	unsigned int n;
	
	std::cout << "Enter x and N by space: ";
	std::cin >> x >> n;

	std::cout << "with recursive method, x^N = " << func(x, n);

	double y = 1.0;
	while(n != 0)
	{
		if(n % 2 != 0)
		{
			y = y * x;
		}
		
		x = x * x;
		n = n / 2;
	}
	std::cout << "\nwith iterative method, x^N = " << y;
	
	return 0;
}