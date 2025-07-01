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

term *mergePolynomial(term *polynomial1, term *polynomial2);

term *sortPolynomial(term *polynomial);

term *addPolynomial(term *polynomial1, term *polynomial2);

template <typename T>
term *scalarMultiplyPolynomial(term *polynomial, T scalar);

term *subtractPolynomial(term *polynomial1, term *polynomial2);

term *multiplyWithMonomial(term *polynomial, term *monomial);

term *multiplyPolynomial(term *polynomial1, term *polynomial2);

term *dividePolynomial(term *polynomial1, term *polynomial2);

term *differentiate(term *polynomial);

term *integrate(term *polynomial);

#endif
