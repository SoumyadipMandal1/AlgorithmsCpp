#ifndef HASHING_HPP
#define HASHING_HPP

#include <stdexcept>

class directHash
{
  private:
    static const int MAX = 1000;   // Hash Table size
    bool hashTable[MAX] = {false}; // Hash Table

  public:
    void insert(int key)
    {
        // If key is in the range of Hash table
        if (key >= 0 && key < MAX)
            hashTable[key] = true;

        else
            throw std::invalid_argument("Key is out of range.");
    }

    bool search(int key)
    {
        if (key >= 0 && key < MAX)
            return hashTable[key];
        else
            return false;
    }

    void remove(int key)
    {
        if (key >= 0 && key < MAX)
            hashTable[key] = false;
        else
            throw std::invalid_argument("Key is out of range.");
    }
};

#endif
