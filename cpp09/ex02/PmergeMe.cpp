#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
    // Constructor implementation
}

PmergeMe::~PmergeMe() {
    // Destructor implementation
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
    
}

void PmergeMe::checkArg(int ac, char** av) 
{
    std::unordered_set<unsigned int> uniqueElements;

    for (int i  = 1; i < ac; i++)//check for duplicates
    {
        int element = std::stoi(av[i]);
        if (uniqueElements.find(element) != uniqueElements.end())
        {
            throw std::invalid_argument("Error: Duplicate element found");
        }
        uniqueElements.insert(element);
    }
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{

}

void PmergeMe::addElement(int element) {
    // Add element to the collection
}

void PmergeMe::mergeElements() {
    // Merge elements in the collection
}

void PmergeMe::printElements() const {
    // Print elements in the collection
}