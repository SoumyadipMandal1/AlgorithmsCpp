#include <math.h>
#include <string>

int hash(std::string string)
{
    int sum = 0, i = 0;

    for (char character : string)
        sum += character * pow(2, i);

    return sum;
}

bool rabin_karp(std::string string, std::string substring)
{
    // Initializing hash
    int hashval = hash(substring);

    int first, length, hashtemp, flag;
    first = 0;
    length = substring.size();

    // Rabin Karp
    while (first + length <= string.size())
    {
        hashtemp = hash(string.substr(first, length));
        if (hashtemp == hashval)
        {
            flag = 1;
            // Checking  the string
            for (int i = first; i < first + length; i++)
            {
                if (string[i] != substring[i - first])
                    break;
            }
            if (flag)
                return true;
        }
        first++;
    }

    return false;
}
