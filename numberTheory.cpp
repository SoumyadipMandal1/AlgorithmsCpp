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
