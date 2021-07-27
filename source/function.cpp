#include "function.h"

int factorial(int n)
{
	int fact = 1;
	for (int i = 2; i <= n; i++)
	{
		fact *= i;
	}
	return fact;
}

bool testnum(string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i]<'0' || str[i]>'9')
			if (str[i] != ',')
				return false;

	}
	return true;
}
void input(double  &real, double &imaginary, double &angle, double &r)
{

	string testimp;
	do {
		cout << "¬ведите действительную часть" << endl;
		cin >> testimp;
	} while (!testnum(testimp));
	real = stod(testimp);
	do {
		cout << "¬ведите мнимую часть" << endl;
		cin >> testimp;
	} while (!testnum(testimp));
	imaginary = stod(testimp);
	angle = atan2(imaginary, real);
	r = real / cos(angle);
}
void compow(int n, double  &real, double &imaginary, double &angle, double &r)
{
	r = pow(r, n);
	angle *= n;
	real = r * cos(angle);
	imaginary = r * sin(angle);

}
