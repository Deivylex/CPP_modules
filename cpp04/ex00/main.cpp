#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

// When creating virtual functions, it is important for the destructor to be virtual as well to ensure proper resource deallocation.
// It's only necessary to add 'virtual' and 'override' in the header file.
// This is done so that child functions can override the parent function.

int main ()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
const WrongAnimal* w_ani = new WrongAnimal;
const WrongAnimal* w_cat = new WrongCat;

std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
std::cout << w_cat->getType() << "" << std::endl;

i->makeSound();
j->makeSound();
meta->makeSound();
w_ani->makeSound();
w_cat->makeSound();

delete meta;
delete j;
delete i;
delete w_ani;
delete w_cat;

return 0;
}