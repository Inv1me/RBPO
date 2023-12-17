#include <iostream>
#include <math.h>
export module Math;
export namespace Math
{
	export class Complex
	{
	private:
		double mod;
		double arg;

	public:
		//Конструктор по умолчанию
		Complex()
		{
			mod = 0;
			arg = 0;
		}
		//Конструктор инициализации
		Complex(double real, double image)
		{
			mod = sqrt(real * real + image * image);
			arg = atan2(image, real);
			if (mod < 6.6613381477509392e-15)
				mod = 0;
			if ((arg > 3.1415926535897) && (arg < 3.1415926535898))
				arg = 0;
		}
		//Конструктор преобразования
		Complex(double a)
		{
			mod = a;
			arg = 0;
		}
		static Complex FromExponentialForm(double mod, double arg)
		{

			return Complex(mod * cos(arg), mod * sin(arg));
		}
		static Complex FromAlgebraicForm(double real, double img)
		{
			Complex a;
			a.mod = sqrt(real * real + img * img);
			a.arg = atan2(img, real);
			return a;
		}
		double Re() const
		{
			return mod * cos(arg);
		}
		double Im() const
		{
			return mod * sin(arg);
		}
		double Mod() const
		{
			return mod;
		}
		double Arg() const
		{
			return arg;
		}
		explicit operator double() const {
			return this->Re();
		}
		Complex operator-() const
		{
			return Complex(-1 * this->Re(), -1 * this->Im());
		}
		Complex& operator++()
		{
			double real = this->Re() + 1;
			double img = this->Im();
			this->mod = sqrt(real * real + img * img);
			this->arg = atan2(img, real);
			return *this;
		}
		Complex operator++ (int) {
			Complex copy(*this);
			double real = this->Re() + 1;
			double img = this->Im();
			this->mod = sqrt(real * real + img * img);
			this->arg = atan2(img, real);
			return copy;
		}
		Complex& operator--()
		{
			double real = this->Re() - 1;
			double img = this->Im();
			this->mod = sqrt(real * real + img * img);
			this->arg = atan2(img, real);
			return *this;
		}
		Complex operator-- (int) {
			Complex copy(*this);
			double real = this->Re() - 1;
			double img = this->Im();
			this->mod = sqrt(real * real + img * img);
			this->arg = atan2(img, real);
			return copy;
		}

		Complex& operator+=(Complex a)
		{
			double real = Re();
			double img = Im();
			real += a.Re();
			img += a.Im();
			mod = sqrt(real * real + img * img);
			arg = atan2(img, real);
			return *this;
		}
		Complex& operator-=(Complex a)
		{
			double real = Re();
			double img = Im();
			real -= a.Re();
			img -= a.Im();
			mod = sqrt(real * real + img * img);
			arg = atan2(img, real);
			return *this;
		}
		Complex& operator*=(Complex a)
		{
			mod *= a.mod;
			arg += a.arg;
			return *this;
		}
		Complex& operator/=(Complex a)
		{
			mod /= a.mod;
			arg -= a.arg;
			return *this;
		}
		friend Complex operator+ (const Complex& left, const Complex& right);
		friend Complex operator- (const Complex& left, const Complex& right);
		friend Complex operator* (const Complex& left, const Complex& right);
		friend Complex operator/ (const Complex& left, const Complex& right);
		friend Complex operator ""i(long double im);
		friend Complex operator ""i(unsigned long long im);
		friend std::ostream& operator<<(std::ostream& stream, const Complex& a);
		friend Complex Sin(const Complex& value);
	};

	export Complex operator+(const Complex& left, const Complex& right)
	{
		double real = left.Re() + right.Re();
		double img = left.Im() + right.Im();
		return Complex(real, img);
	}

	export Complex operator-(const Complex& left, const Complex& right)
	{
		double real = left.Re() - right.Re();
		double img = left.Im() - right.Im();
		return Complex(real, img);
	}

	export Complex operator*(const Complex& left, const Complex& right)
	{
		double real = left.Mod() * right.Mod();
		double img = left.Arg() + right.Arg();
		double real1 = real * cos(img);
		double img1 = real * sin(img);
		return Complex(real1, img1);
	}

	export Complex operator/(const Complex& left, const Complex& right)
	{
		double real = left.Mod() / right.Mod();
		double img = left.Arg() - right.Arg();
		double real1 = real * cos(img);
		double img1 = real * sin(img);
		return Complex(real1, img1);
	}

	export Complex operator ""i(unsigned long long im) {
		return Complex(0.0, static_cast<double>(im));
	}

	export Complex operator ""i(long double im) {
		return Complex(0.0, static_cast<double>(im));
	}
	export std::ostream& operator<<(std::ostream& stream, const Complex& a) {
		if (a.Im() < 0) {
			stream << a.Re() << " " << a.Im() << "i";
		}
		else {
			stream << a.Re() << " + " << a.Im() << "i";
		}
		return stream;
	}

	export int FindGreatestCommonDivisor(int a, int b) {
		if (a < 0) {
			a *= -1;
		}
		if (b < 0) {
			b *= -1;
		}
		while (a != 0 && b != 0) {
			if (a > b) {
				a %= b;
			}
			else {
				b %= a;
			}
		}
		return a + b;
	}

	export int FindLeastCommonMultiple(int a, int b) {
		return abs(a * b) / FindGreatestCommonDivisor(a, b);
	}

	export Complex Sin(const Complex& z) {
		Complex a = 2 * z;
		return Complex(sin((double)a));
	}

	export class Rational {
	private:
		int nominator;
		int denominator;
		void normalizator() {
			if (denominator < 0) {
				denominator *= -1;
				nominator *= -1;
			}
			int nod = FindGreatestCommonDivisor(nominator, denominator);
			nominator /= nod;
			denominator /= nod;
		}
	public:
		Rational() {
			nominator = 0;
			denominator = 1;
		}

		Rational(int x, int y) {
			nominator = x;
			denominator = y;
			this->normalizator();
		}

		Rational(int x) {
			nominator = x;
			denominator = 1;
		}
		int Nominator() const {
			return nominator;
		}
		int Denominator() const {
			return denominator;
		}
		explicit operator double() const {
			return static_cast<double>(nominator) / denominator;
		}
		Rational operator-() {
			Rational a(*this);
			a.nominator *= -1;
			return a;
		}
		Rational& operator++ () {
			Rational a(*this);
			nominator += a.denominator;
			normalizator();
			return *this;
		}
		Rational operator++ (int) {
			Rational a(*this);
			nominator += a.denominator;
			normalizator();
			return a;
		}
		Rational& operator-- () {
			Rational a(*this);
			nominator -= a.denominator;
			normalizator();
			return *this;
		}
		Rational operator-- (int) {
			Rational a(*this);
			nominator -= a.denominator;
			normalizator();
			return a;
		}
		Rational& operator+=(Rational a) {
			int Nominator = nominator * a.denominator + denominator * a.nominator;
			int Denominator = denominator * a.denominator;
			nominator = Nominator;
			denominator = Denominator;
			normalizator();
			return *this;
		}
		Rational& operator-=(Rational a) {
			int Nominator = nominator * a.denominator - denominator * a.nominator;
			int Denominator = denominator * a.denominator;
			nominator = Nominator;
			denominator = Denominator;
			normalizator();
			return *this;
		}
		Rational& operator*=(Rational a) {
			denominator *= a.denominator;
			nominator *= a.nominator;
			normalizator();
			return *this;
		}
		Rational& operator/=(Rational a) {
			denominator *= a.nominator;
			nominator *= a.denominator;
			normalizator();
			return *this;
		}
		friend Rational operator+ (const Rational& left, const Rational& right);
		friend Rational operator- (const Rational& left, const Rational& right);
		friend Rational operator* (const Rational& left, const Rational& right);
		friend Rational operator/(const Rational& left, const Rational& right);
		friend bool operator==(const Rational& left, const Rational& right);
		friend bool operator>(const Rational& left, const Rational& right);
		friend bool operator<(const Rational& left, const Rational& right);
		friend bool operator>=(const Rational& left, const Rational& right);
		friend bool operator<=(const Rational& left, const Rational& right);
		friend std::ostream& operator<< (std::ostream& stream, const Rational& rational);
		friend Rational Sin(const Rational& value);
	};

	export Rational operator+ (const Rational& left, const Rational& right) {
		int denominator = FindLeastCommonMultiple(left.denominator, right.denominator);
		int nominator = denominator / left.denominator * left.nominator;
		nominator += denominator / right.denominator * right.nominator;
		return Rational(nominator, denominator);
	}

	export Rational operator-(const Rational& left, const Rational& right)
	{
		int denominator = FindLeastCommonMultiple(left.denominator, right.denominator);
		int nominator = denominator / left.denominator * left.nominator;
		nominator -= denominator / right.denominator * right.nominator;
		return Rational{ nominator, denominator };
	}

	export Rational operator*(const Rational& left, const Rational& right)
	{
		return Rational(left.nominator * right.nominator, right.denominator * left.denominator);
	}

	export Rational operator/(const Rational& left, const Rational& right)
	{
		return Rational(left.nominator * right.denominator, left.denominator * right.nominator);
	}

	export bool operator==(const Rational& left, const Rational& right)
	{
		return left.nominator == right.nominator && left.denominator == right.denominator;
	}

	export bool operator>(const Rational& left, const Rational& right)
	{
		int lcm = FindLeastCommonMultiple(left.denominator, right.denominator);
		return lcm / left.denominator * left.nominator > lcm / right.denominator * right.nominator;
	}

	export bool operator<(const Rational& left, const Rational& right)
	{
		int lcm = FindLeastCommonMultiple(left.denominator, right.denominator);
		return lcm / left.denominator * left.nominator < lcm / right.denominator * right.nominator;
	}

	export bool operator>=(const Rational& left, const Rational& right)
	{
		int lcm = FindLeastCommonMultiple(left.denominator, right.denominator);
		return lcm / left.denominator * left.nominator >= lcm / right.denominator * right.nominator;
	}

	export bool operator<=(const Rational& left, const Rational& right)
	{
		int lcm = FindLeastCommonMultiple(left.denominator, right.denominator);
		return lcm / left.denominator * left.nominator <= lcm / right.denominator * right.nominator;
	}

	export std::ostream& operator<<(std::ostream& stream, const Rational& rational) {
		stream << rational.nominator << "/" << rational.denominator;
		return stream;
	}

	export Rational Sin(const Rational& r) {
		return Rational(sin((double)r));
	}


	export Complex f(const Complex& z) {
		Complex a = Complex(0.0, 1.0);
		Complex result = a - z * Sin(z);
		return result;
	}

	export Rational f(const Rational& r) {
		Rational a(1, 2);
		Rational result = a - r * Sin(2*r);
		return result;
	}

	export double f(const double& x) {
		double a = 0.5;
		double result = a - x * sin(2 * x);
		return result;
	}
}
