#pragma once

#include <iostream>
#include <exception>

template <typename T>
class Array
{
    private:
    T*   _data;
    unsigned int _size;

    public:
    Array() : _data(nullptr),  _size(0) {}
    Array(unsigned int N) : _data(new T[N]), _size(N) {}
    ~Array() { delete[] _data; }
    Array(const Array& other) {            
            
            _data =  new T[other._size];
            for (unsigned int i = 0; i < other._size; i++ )
                _data[i] = other._data[i];
            _size = other._size;
    }
    Array& operator=(const Array& other) {

        if (this != &other)
        {
            if (_size > 0)
            {
                delete[] _data;
                if(other._size > 0)
                {

                    _data =  new T[other._size];
                    for (unsigned int i = 0; i < other._size; i++)
                        _data[i] = other._data[i];
                    _size = other._size;
                }
                else
                {
                    _data = other._data;
                    _size = other._size;
                }
                return *this;
            }
            else
            {
                if(other._size > 0)
                {

                    _data = new T[other._size];
                    for (unsigned int i = 0; i < other._size; i++)
                        _data[i] = other._data[i];
                    _size = other._size;
                }
                else
                {
                    _data = other._data;
                    _size = other._size;
                }
                return *this;
            }
        }
        return *this;
    }

    T& operator[](unsigned int index) {

        if(index >= _size)
            throw std::out_of_range("Index out of bounds");
        return _data[index]; 
    }

    
    const T& operator[](unsigned int index) const {

        if(index >= _size)
            throw std::out_of_range("Index out of bounds");
        return _data[index]; 
    }

    unsigned int size() { return _size; }
};