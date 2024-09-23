#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal 
{
    private :

    Brain* brain;

    public : 
    
    Cat();
    Cat(const Cat& other);
    Cat& operator=(const Cat& other);
    ~Cat();

    void makeSound() const override; 
    std::string getBrainIdea(int index) const;
    void setBrainIdea(int index, const std::string& idea);
};

#endif