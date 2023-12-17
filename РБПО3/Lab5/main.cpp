#include <iostream>
#include <complex>
#define _SILENCE_NONFLOATING_COMPLEX_DEPRECATION_WARNING
import Math;
using namespace std;
int main()
{
	double real, img, nominator, denominator, x;
	cout << "Enter the real part:";
	cin >> real;
	cout << "Enter the real image:";
	cin >> img;
	Math::Complex z(real, img);
	std::cout << "The result of Complex function:" << "f(" << z << ") = " << Math::f(z) << std::endl;
	cout << "Enter the nominator:";
	cin >> nominator;
	cout << "Enter the denominator:";
	cin >> denominator;
	Math::Rational r(nominator, denominator);
	cout << "The result of Rational function:" << "f(" << r << ") = " << Math::f(static_cast<double>(r)) << endl;
	cout << "Enter the number: ";
	cin >> x;
	cout << "The result of function:" << "f(" << x << ") = " << Math::f(x) << endl;
	return 0;
}