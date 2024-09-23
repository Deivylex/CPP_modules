#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main ()// chequeo de para proteger clases 
{
    //const AAnimal* a = new AAnimal();
    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();
    const WrongAnimal* w_ani = new WrongAnimal;
    const WrongAnimal* w_cat = new WrongCat;

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << w_cat->getType() << "" << std::endl;

    i->makeSound();
    j->makeSound();
    w_ani->makeSound();
    w_cat->makeSound();

    const AAnimal *more[6];
    for (int i = 0; i < 3; i++)
        more[i] = new Dog();
    for (int i = 3; i < 6; i++)
        more[i] = new Cat();
    for (int i = 0; i < 6; i++)
        more[i]->makeSound();
    delete j;
    delete i;
    delete w_ani;
    delete w_cat;
    for(int i = 0; i < 6; i++)
        delete more[i];
    return 0;
}
