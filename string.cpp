#include <string>

std::string reverse(std::string str)
{
    // Pointers
    int i = 0;
    int j = str.size() - 1;

    // Temporary character variable for swapping
    char temp;

    while (i != j and i + 1 != j)
    {
        // Swapping
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;

        // Updating the pointers
        i++;
        j--;
    }

    return str;
}

int hash(std::string string)
{
    int sum = 0, i = 0;

    for (char character : string)
        sum += character * (1 << i);

    return sum;
}

bool rabin_karp(std::string string, std::string substring)
{
    // Initializing hash
    int hashval = hash(substring);

    int first, length, flag;
    first = 0;
    length = substring.size();

    // Rabin Karp
    int hashtemp = hash(string.substr(first, length));
    while (first + length <= string.size())
    {
        if (hashtemp == hashval)
        {
            flag = 1;
            // Checking  the string
            for (int i = first; i < first + length; i++)
            {
                if (string[i] != substring[i - first])
                {
                    flag = 0;
                    break;
                }
            }
            if (flag)
                return true;
        }

        if (first + length == string.size())
            return false;
        // Updating hash value
        hashtemp = (hashtemp - string[first]) / 2 + string[first + length] * (1 << (substring.size() - 1));
        first++;
    }

    return false;
}
