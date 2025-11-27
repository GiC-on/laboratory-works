// Лабораторная работа 8 вариант 11
// Чупов Максим ЭиН-2 1к.

/*
TO-DO LIST
 - fix Sx's while loop taking too much time (iterations) to calculate S(x) value
 - make output look somehow better
*/

#include <iostream>
#include <iomanip>
#include <cmath>

double Yx(double x)
{
	return (2.0 * x * sin(x) - 2.0 + cos(x)) / 4.0;
}

void Sx(double x, double eps)
{
	double yx = Yx(x);
	long long k = 2;
	long long iter = 1;

	double prev = cos(k * x) / (k * k - 1);
	double sum = prev;

	while(abs(yx - sum) > eps)
	{
		k++;
		iter++;
		prev = -1.0 * cos(k * x) / (k * k - 1);
		sum += prev;
	}

	std::cout << std::setw(15) << sum << "|" << std::setw(5) << iter << "\n";
}

int main()
{
	double  a = -1.0,
			b = 1.3,
			h = (a + b) / 10.0,
			eps = 1.0e-5;

	std::cout   << "from: " << a << " to: " << b << " step: " << h
				<< " accuracy: " << eps << "\n";
	std::cout   << std::setw(6) << "x |" << std::setw(16) << "Y(x)    |"
				<< std::setw(16) << "S(x)    |" << std::setw(6) << " iter"
				<< "\n----------------------------------------------\n";

	for(double x = a; x < b + eps; x += h)
	{
		std::cout << std::setw(5) << x << "|" << std::setw(15) << Yx(x) << "|";
		Sx(x, eps);
	}

	return 0;
}