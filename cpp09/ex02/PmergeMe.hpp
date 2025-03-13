#pragma once

class PmergeMe
{
    private:

    /* data */

    public:

    PmergeMe();
    ~PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);

    void addElement(int element);
    void mergeElements();
    void printElements();

};
