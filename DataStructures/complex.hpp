#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>
#include <math.h>

template <typename T>
class complex
{
  private:
    T real;
    T imaginary;

  public:
    complex(T real, T imaginary)
    {
        this->real = real;
        this->imaginary = imaginary;
    }

    complex operator+(const complex &other) const
    {
        return complex(real + other.real, imaginary + other.imaginary);
    }

    complex operator-(const complex &other) const
    {
        return complex(real - other.real, imaginary - other.imaginary);
    }

    complex operator*(const complex &other) const
    {
        T Real = real * other.real - imaginary * other.imaginary;
        T Imaginary = real * other.imaginary + imaginary * other.real;

        return complex(Real, Imaginary);
    }

    double modulus()
    {
        return pow(pow(real, 2) + pow(imaginary, 2), 0.5);
    }

    complex operator/(const complex &other) const
    {
        double Real = (double)(real * other.real + imaginary * other.imaginary) / (double)(other.real * other.real + other.imaginary * other.imaginary);
        double Imaginary = (double)(imaginary * other.real - real * other.imaginary) / (double)(other.real * other.real + other.imaginary * other.imaginary);

        return complex(Real, Imaginary);
    }

    void print()
    {
        std::cout << real << " + i" << imaginary;
    }
};

#endif
