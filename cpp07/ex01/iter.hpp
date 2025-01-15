#pragma once 

#include <iostream>

template <typename T, typename F>

void iter(T* array, size_t lenth, F funtion)
{
    for (size_t i = 0; i < lenth; i++)
    {
        funtion(array[i]);
    }
    
}

void printInt(int n) {
    std::cout << n << " ";
}

void printString(const std::string& str) {
    std::cout << str << " ";
}

template <typename T>
void increment(T& value) {
    value += 1;
}