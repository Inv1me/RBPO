module;

#include <cmath>
#include <iostream>

export module Math:Complex;
export namespace Math
{
    class Complex {
    private:
        double m_mod;
        double m_arg;

    public:
        Complex() {
            m_mod = 0;
            m_arg = 0;
        }

        Complex(double re, double im) {
            m_mod = sqrt(re * re + im * im);
            m_arg = (re == 0 && im == 0) ? 0 : atan2(im, re);
        }

        Complex(double mod) {
            m_mod = mod;
            m_arg = 0;
        }

        static Complex FromExponentialForm(double m_mod, double m_arg) {
            return Complex(m_mod * cos(m_arg), m_mod * sin(m_arg));
        }

        static Complex FromAlgebraicForm(double re, double im) {
            return Complex(re, im);
        }

        double Re() const {
            return m_mod * cos(m_arg);
        }

        double Im() const {
            return m_mod * sin(m_arg);
        }

        double Mod() const {
            return m_mod;
        }

        double Arg() const {
            return m_arg;
        }

        explicit operator double() const {
            return Re();
        }

        Complex operator-() const {
            return Complex(-Re(), -Im());
        }

        Complex operator++(int) {
            Complex temp(*this);
            ++(*this);
            return temp;
        }

        Complex& operator++() {
            double m_re = Re();
            m_re += 1;
            double temp_im = Im();
            m_mod = sqrt(m_re * m_re + temp_im * temp_im);
            m_arg = (m_re == 0 && temp_im == 0) ? 0 : atan2(temp_im, m_re);
            return *this;
        }

        Complex operator--(int) {
            Complex temp(*this);
            --(*this);
            return temp;
        }

        Complex& operator--() {
            double m_re = Re();
            m_re -= 1;
            double temp_im = Im();
            m_mod = sqrt(m_re * m_re + temp_im * temp_im);
            m_arg = (m_re == 0 && temp_im == 0) ? 0 : atan2(temp_im, m_re);
            return *this;
        }

        Complex& operator+=(const Complex& other) {
            double m_re = Re();
            double m_im = Im();
            m_re += other.Re();
            m_im += other.Im();

            m_mod = sqrt(m_re * m_re + m_im * m_im);
            m_arg = (m_re == 0 && m_im == 0) ? 0 : atan2(m_im, m_re);

            return *this;
        }

        Complex& operator-=(const Complex& other) {
            double m_re = Re();
            double m_im = Im();
            m_re -= other.Re();
            m_im -= other.Im();
            m_mod = sqrt(m_re * m_re + m_im * m_im);
            m_arg = (m_re == 0 && m_im == 0) ? 0 : atan2(m_im, m_re);
            return *this;
        }

        Complex& operator*=(const Complex& other) {
            double temp_re = Re() * other.Re() - Im() * other.Im();
            double temp_im = Re() * other.Im() + Im() * other.Re();
            m_mod = sqrt(temp_re * temp_re + temp_im * temp_im);
            m_arg = atan(temp_im / temp_re);
            return *this;
        }

        Complex& operator/=(const Complex& other) {
            double denominator = other.Re() * other.Re() + other.Im() * other.Im();
            double temp_re = (Re() * other.Re() + Im() * other.Im()) / denominator;
            double temp_im = (Im() * other.Re() - Re() * other.Im()) / denominator;
            m_mod = sqrt(temp_re * temp_re + temp_im * temp_im);
            m_arg = atan(temp_im / temp_re);
            return *this;
        }

        friend Complex operator-(const Complex& lhs, const Complex& rhs);

    };

    Complex operator+(const Complex& lhs, const Complex& rhs) {
        return Complex(lhs.Re() + rhs.Re(), lhs.Im() + rhs.Im());
    }

    Complex operator-(const Complex& lhs, const Complex& rhs)
    {
        double _re1 = lhs.m_mod * cos(lhs.m_arg);
        double _re2 = rhs.m_mod * cos(rhs.m_arg);
        double _im1 = lhs.m_mod * sin(lhs.m_arg);
        double _im2 = rhs.m_mod * sin(rhs.m_arg);
        double _re = round((_re1 - _re2) * 1E5) / 1E5;
        double _im = round((_im1 - _im2) * 1E5) / 1E5;
        return Complex(_re, _im);
    }

    Complex operator*(const Complex& lhs, const Complex& rhs) {
        double realPart = lhs.Re() * rhs.Re() - lhs.Im() * rhs.Im();
        double imagPart = lhs.Re() * rhs.Im() + lhs.Im() * rhs.Re();
        return Complex(realPart, imagPart);
    }

    Complex operator/(const Complex& lhs, const Complex& rhs) {
        double denominator = rhs.Re() * rhs.Re() + rhs.Im() * rhs.Im();
        double realPart = (lhs.Re() * rhs.Re() + lhs.Im() * rhs.Im()) / denominator;
        double imagPart = (lhs.Im() * rhs.Re() - lhs.Re() * rhs.Im()) / denominator;
        return Complex(realPart, imagPart);
    }

    Complex operator""i(long double imag) {
        return Math::Complex(0, imag);
    }

    Complex operator""i(unsigned long long imag) {
        return Math::Complex(0, imag);
    }

    std::ostream& operator<<(std::ostream& os, const Math::Complex& complex) {
        os << complex.Re();
        if (complex.Im() >= 0) {
            os << " + " << complex.Im() << "i";
        }
        else {
            os << " - " << -complex.Im() << "i";
        }
        return os;
    }
}