#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal 
{
    private:
        Brain* brain;

    public:
        Dog();
        Dog(const Dog& other);
        Dog& operator=(const Dog& other);
        ~Dog();

        std::string getBrainIdea(int index) const;
        void setBrainIdea(int index, const std::string& idea);
        void makeSound() const override;
};

#endif