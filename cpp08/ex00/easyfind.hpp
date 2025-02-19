#pragma once
#include <iostream>
#include <algorithm>

template <typename T>

typename T::iterator easyfind(T &cont, int ref)
{
    typename T::iterator it =  std::find(cont.begin(), cont.end(), ref);
    if (it != cont.end())
        return it;
    else
        throw std::runtime_error("Value not found in container");
}