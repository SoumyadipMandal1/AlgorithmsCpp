#ifndef POLYNOMIAL_HPP
#define POLYNOMIAL_HPP

struct term
{
    float coefficient;
    int exponent;
    struct term *next;

    term() = default;

    term(float coefficient, int exponent) : coefficient(coefficient),
                                            exponent(exponent),
                                            next(nullptr) {}
};

typedef struct term term;

term *merge(term *polynomial1, term *polynomial2);

term *sort(term *polynomial);

term *add(term *polynomial1, term *polynomial2);

template <typename T>
term *scalarmultiply(term *polynomial, T scalar);

term *subtract(term *polynomial1, term *polynomial2);

#endif
