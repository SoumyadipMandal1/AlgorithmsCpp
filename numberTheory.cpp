#include <vector>

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int gcd(int a, int b)
{
    if (b)
        return gcd(b, a % b);
    else
        return a;
}

int optimized_gcd(int a, int b)
{
    if (a < b)
        return optimized_gcd(b, a);

    if (b)
    {
        // Uses least remainder instead of the usual remainder
        if (a % b > b / 2)
            return gcd(b, b - a % b);
        else
            return gcd(b, a % b);
    }
    else
        return a;
}

//        gcd    bezout's coefficients
std::pair<int, std::pair<int, int>> extended_gcd(int a, int b)
{
    // let a = bq + r

    // Initialization
    std::pair<int, int> gcd = {a, b};
    std::pair<int, int> bezout_coefficient_x = {1, 0};
    std::pair<int, int> bezout_coefficient_y = {0, 1};

    // Extended Euclidean algorithm
    int quotient;
    while (gcd.second)
    {
        quotient = gcd.first / gcd.second;
        gcd = {gcd.second, gcd.first - quotient * gcd.second};
        bezout_coefficient_x = {bezout_coefficient_x.second,
                                bezout_coefficient_x.first - quotient * bezout_coefficient_x.second};
        bezout_coefficient_y = {bezout_coefficient_y.second,
                                bezout_coefficient_y.first - quotient * bezout_coefficient_y.second};
    }

    return {gcd.first, {bezout_coefficient_x.first, bezout_coefficient_y.first}};
}

int horner(std::vector<int> coefficient, int x, int length)
{
    // If an array [a0, a1, a2, ..., an] is given, then
    // a0 + a1 * x + a2 * x^2 + ... + an * x^n is returned
    // a0 + x * (a1 + x* (a2 + ... + x * (an-1 + x * an)))

    int result = 0;

    for (int i = length - 1; i >= 0; i--)
        result = coefficient[i] + result * x;

    return result;
}

int factorial(int n)
{
    int factorial = 1;

    while (n > 1)
    {
        factorial *= n;
        n--;
    }

    return factorial;
}

int permutation(int n, int k)
{
    return factorial(n) / factorial(n - k);
}

int combination(int n, int k)
{
    return factorial(n) / (factorial(k) * factorial(n - k));
}

bool isPrime(int n)
{
    // TODO : Optimize this function using recent primality tests
    if (n <= 1)
        return false;

    else if (n == 2 || n == 3)
        return true;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

std::vector<int> primeFactorize(int n)
{
    int iter;                      // Iterates through numbers from 2 to sqrt(n)
                                   // to check if it can be factorised
    bool isPrime;                  // Flag to check if the number is prime or not
    std::vector<int> primeFactors; // Stores the prime factors of the number

    while (true)
    {
        isPrime = true; // Considering the number to be prime at first
        iter = 2;       // Iterating from 2 because 1 divides any number

        while (iter * iter <= n)
        {
            if (n % iter == 0) // If the number is composite
            {
                primeFactors.push_back(iter); // Pushing the prime factor
                n /= iter;                    // Updating the number
                isPrime = false;              // The number is not prime
                break;
            }
        }

        // If the number becomes prime
        if (isPrime)
        {
            primeFactors.push_back(n);
            break;
        }
    }

    return primeFactors;
}
