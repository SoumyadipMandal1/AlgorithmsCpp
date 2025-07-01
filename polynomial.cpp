#include "polynomial.hpp"
#include <utility>

// All polynomials are assumed to be sorted in descending order
// except for the sorting function

// Zero polynomial is denoted by nullptr

// An IMPORTANT thing I want to tell to those who want to read this code:
// I found out that creating a new term object and then assigning its information of coefficient and exponent
// is slower than changing the information of an already created object
// because no time is spent on finding and giving a memory location.
// So I have used this knowledge in my code by
// changing the values of previous variables without creating new variables as much as possible

term *mergePolynomial(term *polynomial1, term *polynomial2)
{
    // Edge cases
    if (polynomial1 == nullptr)
        return polynomial2;
    else if (polynomial2 == nullptr)
        return polynomial1;

    // Initializing variables
    // result node will be the head of merged polynomial
    term *temp1, *temp2, *result, *resulttemp;
    temp1 = polynomial1;
    temp2 = polynomial2;

    // Initializing Head of result node
    if (temp1->exponent > temp2->exponent)
    {
        result = temp1;
        temp1 = temp1->next;
    }
    else
    {
        result = temp2;
        temp1 = temp2->next;
    }

    resulttemp = result;

    // Merging the two polynomials
    while (temp1 != nullptr and temp2 != nullptr)
    {
        if (temp1->exponent > temp2->exponent)
        {
            resulttemp->next = temp1;
            temp1 = temp1->next;
            resulttemp = resulttemp->next;
        }
        else
        {
            resulttemp->next = temp2;
            temp2 = temp2->next;
            resulttemp = resulttemp->next;
        }
    }

    // Joining the remaining polynomial
    if (temp1 == nullptr)
        resulttemp->next = temp2;
    else if (temp2 == nullptr)
        resulttemp->next = temp1;

    return result;
}

term *sortPolynomial(term *polynomial)
{
    // Sorting the terms of polynomial in descending order of its exponents

    // Edge cases
    if (polynomial == nullptr)
        return polynomial;
    else if (polynomial->next == nullptr)
        return polynomial;
    else if (polynomial->next->next == nullptr)
    {
        if (polynomial->exponent >= polynomial->next->exponent)
            return polynomial;
        else
        {
            term *head = polynomial->next;
            polynomial->next = nullptr;
            head->next = polynomial;
            return head;
        }
    }

    term *odd, *even, *oddtemp, *eventemp, *temp;
    odd = polynomial;
    even = polynomial->next;
    temp = polynomial->next;
    oddtemp = odd;
    eventemp = even;

    while (temp->next != nullptr and temp->next->next != nullptr)
    {
        oddtemp->next = temp->next;
        eventemp->next = temp->next->next;
        temp = temp->next;
        oddtemp = oddtemp->next;
        eventemp = eventemp->next;
    }

    if (temp->next != nullptr)
    {
        oddtemp->next = temp->next;
        oddtemp = oddtemp->next;
    }

    oddtemp->next = nullptr;
    eventemp->next = nullptr;

    odd = sortPolynomial(odd);
    even = sortPolynomial(even);

    term *result = mergePolynomial(odd, even);
    return result;
}

term *addPolynomial(term *polynomial1, term *polynomial2)
{
    term *sum = nullptr;
    term *temp1, *temp2;
    temp1 = polynomial1;
    temp2 = polynomial2;

    // Initializing the first term of sum polynomial
    // This loop is for checking whether the first term has non-zero coefficient
    while (sum == nullptr and temp1 != nullptr and temp2 != nullptr)
    {
        if (temp1->exponent > temp2->exponent)
        {
            if (temp1->coefficient)
            {
                sum = temp1;
                temp1 = temp1->next;
            }
            else
                temp1 = temp1->next;
        }
        else if (temp1->exponent < temp2->exponent)
        {
            if (temp2->coefficient)
            {
                sum = temp2;
                temp2 = temp2->next;
            }
            else
                temp2 = temp2->next;
        }
        else
        {
            if (temp1->coefficient + temp2->coefficient)
            {
                temp1->coefficient += temp2->coefficient;
                sum = temp1;
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            else
            {
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }
    }

    // Adding the two polynomials
    while (temp1 != nullptr and temp2 != nullptr)
    {
        if (temp1->exponent > temp2->exponent)
        {
            if (temp1->coefficient)
            {
                sum->next = temp1;
                temp1 = temp1->next;
            }
            else
                temp1 = temp1->next;
        }
        else if (temp1->exponent < temp2->exponent)
        {
            if (temp2->coefficient)
            {
                sum->next = temp2;
                temp2 = temp2->next;
            }
            else
                temp2 = temp2->next;
        }
        else
        {
            if (temp1->coefficient + temp2->coefficient)
            {
                temp1->coefficient += temp2->coefficient;
                sum->next = temp1;
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            else
            {
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }
    }

    // Joining the remaining polynomial
    if (temp1 == nullptr)
        sum->next = temp2;
    else if (temp2 == nullptr)
        sum->next = temp1;

    return sum;
}

template <typename T>
term *scalarMultiplyPolynomial(term *polynomial, T scalar)
{
    term *temp = polynomial; // temporary node for traversal
    while (temp != nullptr)  // traversing the polynomial
        temp->coefficient *= scalar;
    return polynomial;
}

term *subtractPolynomial(term *polynomial1, term *polynomial2)
{
    return addPolynomial(polynomial1, scalarMultiplyPolynomial(polynomial2, -1));
}

term *multiplyWithMonomial(term *polynomial, term *monomial)
{
    // Handling Edge cases
    if (monomial == nullptr)
        // Returns Zero polynomial (Null pointer) because
        // zero times everything is zero and Null pointer is considered as a zero polynomial
        return nullptr;

    if (monomial->coefficient)
    {
        // Initializing variables
        term *temp;
        temp = polynomial;

        while (temp != nullptr)
        {
            temp->coefficient *= monomial->coefficient;
            temp->exponent += monomial->exponent;
            temp = temp->next;
        }

        return polynomial;
    }
    else
        // Returns Zero polynomial (Null pointer) because
        // zero times everything is zero
        return nullptr;
}

term *multiplyPolynomial(term *polynomial1, term *polynomial2)
{
    // Initialization
    term *temp2;
    temp2 = polynomial2;
    polynomial1 = multiplyWithMonomial(polynomial1, temp2);
    temp2 = temp2->next;

    // Multiplying in polynomial1
    while (temp2 != nullptr)
    {
        polynomial1 = addPolynomial(polynomial1, multiplyWithMonomial(polynomial1, temp2));
        temp2 = temp2->next;
    }

    return polynomial1;
}

std::pair<term *, term *> divdePolynomial(term *polynomial1, term *polynomial2)
{
    // This polynomial divides polynomial1 by polynomial2
    // i.e., the result is polynomial1 / polynomial2

    // In this function, I have stored the quotient in new memory locations
    // The first polynomial of the pair is quotient and
    // the secnd pair of the pair is remainder

    term *quotient, *tempQuotient;
    quotient = nullptr;

    // Initialization
    if (polynomial1 != nullptr and polynomial1->exponent >= polynomial2->exponent)
    {
        quotient = new term(polynomial1->coefficient / polynomial2->coefficient, polynomial1->exponent - polynomial2->exponent);
        polynomial1 = subtractPolynomial(polynomial1, multiplyWithMonomial(polynomial2, quotient));
        tempQuotient = quotient;
    }

    // If the quotient is a zero polynomial
    if (quotient == nullptr)
        return {nullptr, polynomial2};

    // Division
    while (polynomial1 != nullptr and polynomial1->exponent >= polynomial2->exponent)
    {
        tempQuotient->next = new term(polynomial1->coefficient / polynomial2->coefficient, polynomial1->exponent - polynomial2->exponent);
        polynomial1 = subtractPolynomial(polynomial1, multiplyWithMonomial(polynomial2, tempQuotient->next));
        tempQuotient = tempQuotient->next;
    }

    return {quotient, polynomial2};
}

term *differentiate(term *polynomial)
{
    term *temp = polynomial;

    while (temp != nullptr)
    {
        if (temp->exponent)
        {
            temp->coefficient *= temp->exponent;
            temp->exponent--;
            temp = temp->next;
        }
    }

    return polynomial;
}

term *integrate(term *polynomial)
{
    term *temp = polynomial;

    while (temp != nullptr)
    {
        temp->coefficient /= (float)temp->exponent;
        temp->exponent++;
        temp = temp->next;
    }

    return polynomial;
}
