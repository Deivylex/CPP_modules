#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <cstdint>

struct Data
{
    int age;
    std::string lastname;
    std::string name;
    std::string city;
};

class Serializer
{
    private :

    Serializer();
    ~Serializer();
    Serializer(const Serializer& other);
    Serializer& operator=(const Serializer& other);

    public :

    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);


};

#endif