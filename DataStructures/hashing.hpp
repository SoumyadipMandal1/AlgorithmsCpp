#ifndef HASHING_HPP
#define HASHING_HPP

#include <stdexcept>

class directHash
{
  private:
    static const int MAX = 1000;   // Hash Table size
    bool hashTable[MAX] = {false}; // Hash Table

  public:
    void insert(int key);

    bool search(int key);

    void remove(int key);
};

#endif
