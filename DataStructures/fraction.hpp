#ifndef FRACTION_HPP
#define FRACTION_HPP

#include "../numberTheory.hpp"
#include <stdexcept>

class fraction
{
  private:
    long long numerator;
    long long denominator;

  public:
    fraction(long long numerator, long long denominator)
    {
        this->numerator = numerator;
        if (denominator)
            this->denominator = denominator;
        else
            throw std::invalid_argument("Denominator cannot be Zero");
    }

    fraction operator+(const fraction &other) const
    {
        long long lcm = (denominator * other.denominator) / gcd(denominator, other.denominator);

        long long Numerator = numerator * (lcm / denominator) + (other.numerator) * (lcm / other.denominator);
        long long Denominator = lcm;

        return fraction(Numerator, Denominator);
    }

    fraction operator-(const fraction &other) const
    {
        long long lcm = (denominator * other.denominator) / gcd(denominator, other.denominator);

        long long Numerator = numerator * (lcm / denominator) - (other.numerator) * (lcm / other.denominator);
        long long Denominator = lcm;

        return fraction(Numerator, Denominator);
    }

    fraction operator*(const fraction &other) const
    {
        long long Numerator = numerator * other.numerator;
        long long Denominator = denominator * other.denominator;

        return fraction(Numerator / gcd(Numerator, Denominator), Denominator / gcd(Numerator, Denominator));
    }

    fraction operator/(const fraction &other) const
    {
        long long Numerator = numerator * other.denominator;
        long long Denominator = denominator * other.numerator;

        return fraction(Numerator / gcd(Numerator, Denominator), Denominator / gcd(Numerator, Denominator));
    }
};

#endif
