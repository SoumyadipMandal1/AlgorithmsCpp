#include <stdlib.h>

struct complex
{
    float real{};
    float imaginary{};

    complex() = default;

    complex(float real, float imaginary)
    {
        this->real = real;
        this->imaginary = imaginary;
    }

    complex operator+(const complex& complex1)
    {
        complex complex3;
        complex3.real      = complex1.real      + real;
        complex3.imaginary = complex1.imaginary + imaginary;
        return complex3;
    }

    complex operator-(const complex& complex2)
    {
        complex complex3;
        complex3.real      = real      - complex2.real;
        complex3.imaginary = imaginary - complex2.imaginary;
        return complex3; 
    }

    complex operator*(const complex& complex2)
    {
        complex complex3;
        complex3.real      = real * complex2.real      - imaginary * complex2.imaginary;
        complex3.imaginary = real * complex2.imaginary + imaginary * complex2.real;
        return complex3;
    }

    complex operator/(const complex& complex2)
    {
        complex complex3;
        float modulus = complex2.real * complex2.real + complex2.imaginary * complex2.imaginary;
        complex3.real = real * ((float) complex2.real / modulus) + imaginary * ((float) complex2.imaginary / modulus);
        complex3.imaginary = - real * ((float) complex2.imaginary / modulus) - imaginary * ((float) complex2.real / modulus);
        return complex3;
    }
};