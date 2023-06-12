#include <stdexcept>
#include <algorithm>
#include <iostream>
#include "MagicalContainer.hpp"

using namespace std;

namespace ariel
{
    //constructor
    MagicalContainer::MagicalContainer()
    {
    }

    MagicalContainer::MagicalContainer(const MagicalContainer& other)
    {
        //the sorted array is copied by value, and a new pointer vector is generated for the new addresses
        this->dynamicArray = other.dynamicArray;
        orderd.clear();
        primes.clear();
        for(int curr : dynamicArray)
        {
            orderd.push_back(&curr);
            cout << "element is " << curr << " pushed back " << *orderd[orderd.size() -1] << endl;
            if(isPrime(curr))
            {
                primes.push_back(&curr);
            }
        }
    }

    //private helper function
    bool MagicalContainer::isPrime(int& num)
    {
        if(num == 2)
            return true;

        if(num < 2 || num % 2 == 0)
            return false;

        for(int i = 3; i*i <= num; i+=2)
        {
            if(num % i == 0)
                return false;
        }

        return true;
    }

    //fuctions
    void MagicalContainer::addElement(int elem)
    {
        //if the element exists already, do nothing -O(n)
        for(auto it = dynamicArray.begin(); it < dynamicArray.end(); ++it)
        {
            if(*it == elem)
            {
                return;
            }
        }

        //otherwise, add it
        dynamicArray.push_back(elem);

        sort(dynamicArray.begin(), dynamicArray.end()); //sorts ascending

        //reset pointers -O(n)/O(nm) can maybe improve?
        orderd.clear();
        primes.clear();
        for(unsigned long i = 0; i < dynamicArray.size(); i++)
        {
            orderd.push_back(&dynamicArray[i]);

            if(isPrime(dynamicArray[i]))
            {
                primes.push_back(&dynamicArray[i]);
            }
        }
    }

    void MagicalContainer::removeElement(int elem)
    {
        bool flag = isPrime(elem);

        //find element by iterating through the vector, and remove -O(n)
        for(auto it = dynamicArray.begin(); it < dynamicArray.end(); ++it)
        {
            if(*it == elem)
            {
                if(flag) //if prime, erase pointer from primes
                {
                    primes.erase(find(primes.begin(), primes.end(), &(*it)));
                }
                dynamicArray.erase(it);
                orderd.erase(find(orderd.begin(), orderd.end(), &(*it)));
                return;
            }
        }

        //if element is not in the container
        throw runtime_error("Element not found");
    }

    unsigned long MagicalContainer::size()
    {
        return dynamicArray.size();
    }
}