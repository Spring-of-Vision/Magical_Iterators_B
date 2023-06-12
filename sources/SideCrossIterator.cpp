#include <stdexcept>
#include <algorithm>
#include <iostream>
#include "MagicalContainer.hpp"

using namespace std;

namespace ariel
{
    //constructors
    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& container) : myContainer(container)
    {
        direction = true;
        if(container.size() == 0)
        {
            element = nullptr;
            next = nullptr;
        }
        else
        {
            element = &(container.orderd[0]);
            
            next = &(container.orderd[container.size() -1]);
            //next is end pointer if only one element
            if(container.size() == 1)
                next++;
        }
    }

    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator& other) : myContainer(other.myContainer), element(other.element), next(other.next), direction(other.direction)
    {
    }

    //functions
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin()
    {
        return SideCrossIterator(myContainer);
    }
    
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end()
    {
        SideCrossIterator temp(myContainer);
        temp.element= &(myContainer.orderd[myContainer.size() -1]);
        temp.element++;
        temp.next = nullptr;
        return temp;
    }

    //operator functions
    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& other)
    {
        //check same exact container (by address) and same element by pointer
        if(&(this->myContainer) != &(other.myContainer))
        {
            throw runtime_error("Cannot assign iterator of different container");
        }
        element = other.element;
        next = other.next;
        return *this;
    }
    bool MagicalContainer::SideCrossIterator::operator== (const SideCrossIterator& other) const
    {
        //check same exact container (by address) and same element
        return (&(this->myContainer) == &(other.myContainer)) && (this->element == other.element);
    }

    bool MagicalContainer::SideCrossIterator::operator!= (const SideCrossIterator& other) const
    {
        return !(*this == other);
    }

    bool MagicalContainer::SideCrossIterator::operator< (const SideCrossIterator& other) const
    {
        //check same exact container (by address) and whether address is more advanced in the dynamic array
        return (&(this->myContainer) == &(other.myContainer)) && (this->element < other.element);
    }

    bool MagicalContainer::SideCrossIterator::operator> (const SideCrossIterator& other) const
    {
        return (&(this->myContainer) == &(other.myContainer)) && (this->element > other.element);
    }

    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++()
    {
        //if element is end
        if(element > &myContainer.orderd[myContainer.size() -1])
        {
            throw runtime_error("Iterator has reached the end");
        }
        
        //if next is end
        if(next > &myContainer.orderd[myContainer.size() -1])
        {
            element = next;
            next = nullptr;
        }
        else
        {
            //middle value or upper-middle in case of even, will be the last
            int** mid = &myContainer.orderd[myContainer.size()/2];
            if(next == mid)
            {
                element = next;
                //update next to end ptr
                next = &(myContainer.orderd[myContainer.size() -1]);
                next++;
            }
            else
            {
                int** temp = element;
                element = next;
                if(direction) //if going up
                {
                    next = ++temp; //up by one from prev element
                    direction = false; //change direction
                    //cout << "element is " << **element << " and next is " << **next << endl;
                }
                else //going down
                {
                    next = --temp; //down by one from prev element
                    direction = true; //change direction
                }
            }
        }

        return *this;
    }

    int MagicalContainer::SideCrossIterator::operator*() const
    {
        //dereference the element itself
        return **element;
    }
}