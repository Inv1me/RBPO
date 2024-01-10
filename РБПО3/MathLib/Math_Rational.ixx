module;

#include <iostream>
#include <cmath>

export module Math:Rational;

import :Functions;
export namespace Math
{
    class Rational {
    private:
        int m_nominator;
        int m_denominator;
        
    public:
        Rational() : m_nominator(0), m_denominator(1) {}

        Rational(int nominator, int denominator){
            ReduceFraction(nominator, denominator);
            m_nominator = nominator;
            m_denominator = denominator;
        }

        Rational(int nominator) : m_nominator(nominator), m_denominator(1) {}

        int Nominator() const {
            return m_nominator;
        }

        int Denominator() const {
            return m_denominator;
        }
        
        explicit operator double() const {
            return double(double(m_nominator) / double(m_denominator));
        }

        Rational operator-() const {
            return Rational(-m_nominator, m_denominator);
        }

        Rational& operator++() {
            m_nominator += m_denominator;
            return *this;
        }

        Rational operator++(int) {
            Rational temp(*this);
            ++(*this);
            return temp;
        }

        Rational& operator--() {
            m_nominator -= m_denominator;
            return *this;
        }

        Rational operator--(int) {
            Rational temp(*this);
            --(*this);
            return temp;
        }

        Rational& operator+=(const Rational& other) {
            m_nominator = m_nominator * other.m_denominator + other.m_nominator * m_denominator;
            m_denominator *= other.m_denominator;
            ReduceFraction(m_nominator, m_denominator);
            return *this;
        }

        Rational& operator-=(const Rational& other) {
            m_nominator = m_nominator * other.m_denominator - other.m_nominator * m_denominator;
            m_denominator *= other.m_denominator;
            ReduceFraction(m_nominator, m_denominator);
            return *this;
        }

        Rational& operator*=(const Rational& other) {
            m_nominator *= other.m_nominator;
            m_denominator *= other.m_denominator;
            ReduceFraction(m_nominator, m_denominator);
            return *this;
        }

        Rational& operator/=(const Rational& other) {
            m_nominator *= other.m_denominator;
            m_denominator *= other.m_nominator;
            ReduceFraction(m_nominator, m_denominator);
            return *this;
        }
    };

    Rational operator+(const Rational& lhs, const Rational& rhs) {
        return Rational(lhs.Nominator() * rhs.Denominator() + rhs.Nominator() * lhs.Denominator(),
            lhs.Denominator() * rhs.Denominator());
    }

    Rational operator-(const Rational& lhs, const Rational& rhs) {
        return Rational(lhs.Nominator() * rhs.Denominator() - rhs.Nominator() * lhs.Denominator(),
            lhs.Denominator() * rhs.Denominator());
    }

    Rational operator*(const Rational& lhs, const Rational& rhs) {
        return Rational(lhs.Nominator() * rhs.Nominator(), lhs.Denominator() * rhs.Denominator());
    }

    Rational operator/(const Rational& lhs, const Rational& rhs) {
        return Rational(lhs.Nominator() * rhs.Denominator(), lhs.Denominator() * rhs.Nominator());
    }
    
    bool operator==(const Rational& lhs, const Rational& rhs) {
        return (lhs.Nominator() == rhs.Nominator()) && (lhs.Denominator() == rhs.Denominator());
    }

    bool operator!=(const Rational& lhs, const Rational& rhs) {
        return (lhs.Nominator() != rhs.Nominator()) || (lhs.Denominator() != rhs.Denominator());
    }

    bool operator<(const Rational& lhs, const Rational& rhs) {
        return lhs.Nominator() * rhs.Denominator() < rhs.Nominator() * lhs.Denominator();
    }

    bool operator>(const Rational& lhs, const Rational& rhs) {
        return rhs < lhs;
    }

    bool operator<=(const Rational& lhs, const Rational& rhs) {
        return !(rhs < lhs);
    }

    bool operator>=(const Rational& lhs, const Rational& rhs) {
        return !(lhs < rhs);
    }

    std::ostream& operator<<(std::ostream& stream, const Rational& rational) {
        stream << rational.Nominator() << "/" << rational.Denominator();
        return stream;
    }
}