#pragma once
#include <iostream>
#include <vector>
#include <unordered_set>

class PmergeMe
{
    private:

    /* data */

    public:

    PmergeMe();
    ~PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);

    void checkArg(int ac, char** av);
    void addElement(int element);
    void mergeElements();
    void printElements() const;

};
