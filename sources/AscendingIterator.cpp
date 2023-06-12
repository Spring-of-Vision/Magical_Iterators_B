#include <stdexcept>
#include <algorithm>
#include <iostream>
#include "MagicalContainer.hpp"

using namespace std;

namespace ariel
{
    //constructors
    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& container) : myContainer(container)
    {
        if(container.size() == 0)
        {
            element = nullptr;
        }
        else
        {
            element = &(container.orderd[0]);
        }
    }

    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator& other) : myContainer(other.myContainer), element(other.element)
    {
    }

    //functions
    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin()
    {
        return AscendingIterator(myContainer);
    }
    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end()
    {
        AscendingIterator temp(myContainer);
        temp.element= &(myContainer.orderd[myContainer.size() -1]);
        temp.element++;
        return temp;
    }

    //operator functions
    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const AscendingIterator& other)
    {
        //check same exact container (by address) and same element by pointer
        if(&(this->myContainer) != &(other.myContainer))
        {
            throw runtime_error("Cannot assign iterator of different container");
        }
        element = other.element;
        return *this;
    }

    bool MagicalContainer::AscendingIterator::operator== (const AscendingIterator& other) const
    {
        //check same exact container (by address) and same element
        return (&(this->myContainer) == &(other.myContainer)) && (this->element == other.element);
    }

    bool MagicalContainer::AscendingIterator::operator!= (const AscendingIterator& other) const
    {
        return !(*this == other);
    }

    bool MagicalContainer::AscendingIterator::operator< (const AscendingIterator& other) const
    {
        //check same exact container (by address) and whether address is more advanced in the dynamic array
        return (&(this->myContainer) == &(other.myContainer)) && (this->element < other.element);
    }

    bool MagicalContainer::AscendingIterator::operator> (const AscendingIterator& other) const
    {
        return (&(this->myContainer) == &(other.myContainer)) && (this->element > other.element);
    }

    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++()
    {
        if(element > &myContainer.orderd[myContainer.size() -1])
        {
            throw runtime_error("Iterator has reached the end");
        }
        //advance address to next element in the array
        element++;
        return *this;
    }

    int MagicalContainer::AscendingIterator::operator*() const
    {
        //dereference the element itself
        return **element;
    }
}