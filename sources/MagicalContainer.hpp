#pragma once

#include <vector>

namespace ariel
{
    class MagicalContainer
    {
        private:
            //fields
            std::vector<int> dynamicArray;
            std::vector<int*> primes;
            //std::vector<int*> orderdCrossed;
            std::vector<int*> orderd;

            //helper functions
            bool isPrime(int&);
            //void orderPointers();

        public:
            //constructors
            MagicalContainer();
            MagicalContainer(const MagicalContainer& other);

            //destructor
            ~MagicalContainer() = default;

            //general fuctions
            void addElement(int elem);
            void removeElement(int elem);
            unsigned long size();

            class AscendingIterator
            {
                private:
                    MagicalContainer& myContainer;
                    int** element;

                public:
                    //constructor
                    AscendingIterator(MagicalContainer& container);
                    AscendingIterator();
                    AscendingIterator(const AscendingIterator& other);

                    ~AscendingIterator() = default;

                    //functions
                    AscendingIterator begin();
                    AscendingIterator end();

                    //operator functions
                    AscendingIterator& operator=(const AscendingIterator& other);
                    bool operator== (const AscendingIterator&) const;
                    bool operator!= (const AscendingIterator&) const;
                    bool operator< (const AscendingIterator&) const;
                    bool operator> (const AscendingIterator&) const;
                    AscendingIterator& operator++();
                    int operator*() const;
            };

            class SideCrossIterator
            { 
                private:
                    MagicalContainer& myContainer;
                    int** element;
                    int** next;
                    bool direction; //direction for next next: true- going up, false- going down

                    //helper function
                    //int** getNext();

                public:
                    //constructor
                    SideCrossIterator(MagicalContainer& container);
                    SideCrossIterator(const SideCrossIterator& other);

                    ~SideCrossIterator() = default;

                    //functions
                    SideCrossIterator begin();
                    SideCrossIterator end();

                    //operator functions
                    SideCrossIterator& operator=(const SideCrossIterator& other);
                    bool operator== (const SideCrossIterator&) const;
                    bool operator!= (const SideCrossIterator&) const;
                    bool operator< (const SideCrossIterator&) const;
                    bool operator> (const SideCrossIterator&) const;
                    SideCrossIterator& operator++();
                    int operator*() const;
            };

            class PrimeIterator
            {
                private:
                    MagicalContainer& myContainer;
                    int** element;

                public:
                    //constructor
                    PrimeIterator(MagicalContainer& container);
                    PrimeIterator(const PrimeIterator& other);

                    ~PrimeIterator() = default;

                    //functions
                    PrimeIterator begin();
                    PrimeIterator end();

                    //operator functions
                    PrimeIterator& operator=(const PrimeIterator& other);
                    bool operator== (const PrimeIterator&) const;
                    bool operator!= (const PrimeIterator&) const;
                    bool operator< (const PrimeIterator&) const;
                    bool operator> (const PrimeIterator&) const;
                    PrimeIterator& operator++();
                    int operator*() const;
            };
    };
}
