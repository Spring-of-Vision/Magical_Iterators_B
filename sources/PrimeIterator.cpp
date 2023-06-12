#include <stdexcept>
#include <algorithm>
#include <iostream>
#include "MagicalContainer.hpp"

using namespace std;

namespace ariel
{
    //constructors
    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& container) : myContainer(container)
    {
        if(container.primes.size() == 0)
        {
            element = nullptr;
        }
        else
        {
            element = &(container.primes[0]);
        }
    }

    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator& other) : myContainer(other.myContainer)
    {
    }

    //functions
    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin()
    {
        return PrimeIterator(myContainer);
    }
    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end()
    {
        PrimeIterator temp(myContainer);
        temp.element= &(myContainer.primes[myContainer.primes.size() -1]);
        temp.element++;
        return temp;
    }

    //operator functions
    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(const PrimeIterator& other)
    {
        //check same exact container (by address) and same element by pointer
        if(&(this->myContainer) != &(other.myContainer))
        {
            throw runtime_error("Cannot assign iterator of different container");
        }
        element = other.element;
        return *this;
    }
    bool MagicalContainer::PrimeIterator::operator== (const PrimeIterator& other) const
    {
        //check same exact container (by address) and same element
        return (&(this->myContainer) == &(other.myContainer)) && (this->element == other.element);
    }

    bool MagicalContainer::PrimeIterator::operator!= (const PrimeIterator& other) const
    {
        return !(*this == other);
    }

    bool MagicalContainer::PrimeIterator::operator< (const PrimeIterator& other) const
    {
        //check same exact container (by address) and whether address is more advanced in the dynamic array
        return (&(this->myContainer) == &(other.myContainer)) && (this->element < other.element);
    }

    bool MagicalContainer::PrimeIterator::operator> (const PrimeIterator& other) const
    {
        return (&(this->myContainer) == &(other.myContainer)) && (this->element > other.element);
    }

    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++()
    {
        if(myContainer.primes.size() == 0 || element > &myContainer.primes[myContainer.primes.size() -1])
        {
            throw runtime_error("Iterator has reached the end");
        }
        //advance address to next element in the array
        element++;
        return *this;
    }

    int MagicalContainer::PrimeIterator::operator*() const
    {
        //dereference the element itself
        return **element;
    }
}