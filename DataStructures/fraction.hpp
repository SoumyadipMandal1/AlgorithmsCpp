#ifndef FRACTION_HPP
#define FRACTION_HPP

#include "../numberTheory.hpp"
#include <iostream>
#include <stdexcept>

class fraction
{
  private:
    long long numerator;
    long long denominator;

  public:
    fraction(long long numerator, long long denominator)
    {
        if (denominator)
        {
            long long GCD = gcd(numerator, denominator);
            this->numerator = numerator / GCD;
            this->denominator = denominator / GCD;
        }
        else
            throw std::invalid_argument("Denominator cannot be Zero");
    }

    fraction operator+(const fraction &other) const
    {
        long long lcm = (denominator * other.denominator) / gcd(denominator, other.denominator);

        long long Numerator = numerator * (lcm / denominator) + (other.numerator) * (lcm / other.denominator);
        long long Denominator = lcm;
        long long GCD = gcd(Numerator, Denominator);

        return fraction(Numerator / GCD, Denominator / GCD);
    }

    fraction operator-(const fraction &other) const
    {
        long long lcm = (denominator * other.denominator) / gcd(denominator, other.denominator);

        long long Numerator = numerator * (lcm / denominator) - (other.numerator) * (lcm / other.denominator);
        long long Denominator = lcm;
        long long GCD = gcd(Numerator, Denominator);

        return fraction(Numerator / GCD, Denominator / GCD);
    }

    fraction operator*(const fraction &other) const
    {
        long long Numerator = numerator * other.numerator;
        long long Denominator = denominator * other.denominator;
        long long GCD = gcd(Numerator, Denominator);

        return fraction(Numerator / GCD, Denominator / GCD);
    }

    fraction operator/(const fraction &other) const
    {
        long long Numerator = numerator * other.denominator;
        long long Denominator = denominator * other.numerator;
        long long GCD = gcd(Numerator, Denominator);

        return fraction(Numerator / GCD, Denominator / GCD);
    }

    void print()
    {
        std::cout << numerator << '/' << denominator;
    }
};

#endif
