#include "Serializer.hpp"

int main()
{
    Data testData;

    testData.age = 5;
    testData.city = "helsinki";
    testData.lastname = "42";
    testData.name = "Hive";

    uintptr_t raw =  Serializer::serialize(&testData);

    Data* deserialize = Serializer::deserialize(raw);

    std::cout << "\nserializer address\n" << &raw << "\n";
    std::cout << "\nData after deserialize\n" << deserialize->age << "\n" 
                                                  << deserialize->name << "\n"
                                                  << deserialize->lastname << "\n"
                                                  << deserialize->city << "\n";

    if (&testData == deserialize)
        std::cout << "\nDeserialize success\n";
    else
        std::cout << "\nDeserialize fail\n";
}