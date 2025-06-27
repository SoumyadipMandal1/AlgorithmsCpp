#include "polynomial.hpp"

// All polynomials are assumed to be sorted in descending order
// except for the sorting function

// An IMPORTANT thing I want to tell to those who want to read this code:
// I found out that creating a new term object and
// then assigning its information of coefficient and exponent
// is slower than changing the information of an already created object
// because no time is spent on finding and giving a memory location.
// So I have used this knowledge repeatedly in my code

term *merge(term *polynomial1, term *polynomial2)
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

term *sort(term *polynomial)
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

    odd = sort(odd);
    even = sort(even);

    term *result = merge(odd, even);
    return result;
}

term *add(term *polynomial1, term *polynomial2)
{
    term *sum;
    term *temp1, *temp2;
    temp1 = polynomial1;
    temp2 = polynomial2;

    // Initializing the sum node
    if (temp1->exponent > temp2->exponent)
    {
        sum = temp1;
        temp1 = temp1->next;
    }
    else if (temp1->exponent < temp2->exponent)
    {
        sum = temp2;
        temp2 = temp2->next;
    }
    else
    {
        temp1->coefficient += temp2->coefficient;
        sum = temp1;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    // Adding the two polynomials
    while (temp1 != nullptr and temp2 != nullptr)
    {
        if (temp1->exponent > temp2->exponent)
        {
            sum->next = temp1;
            temp1 = temp1->next;
        }
        else if (temp1->exponent < temp2->exponent)
        {
            sum->next = temp2;
            temp2 = temp2->next;
        }
        else
        {
            temp1->coefficient += temp2->coefficient;
            sum->next = temp1;
            temp1 = temp1->next;
            temp2 = temp2->next;
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
term *scalarmultiply(term *polynomial, T scalar)
{
    term *temp = polynomial; // temporary node for traversal
    while (temp != nullptr)  // traversing the polynomial
        temp->coefficient *= scalar;
    return polynomial;
}

term *subtract(term *polynomial1, term *polynomial2)
{
    return add(polynomial1, scalarmultiply(polynomial2, -1));
}
