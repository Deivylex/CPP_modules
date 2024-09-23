#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

// When creating virtual functions, it is important for the destructor to be virtual as well to ensure proper resource deallocation.
// It's only necessary to add 'virtual' and 'override' in the header file.
// This is done so that child functions can override the parent function.

int main ()
{
    std::cout << "test ex01" << std::endl;
    const int size = 6;
    Animal* animals[size];

    for (int i = 0; i < size / 2; ++i)
    {
        animals[i] = new Dog();
        Dog* dog = dynamic_cast<Dog*>(animals[i]);
        if (dog)
            dog->setBrainIdea(i, "I love soccer");
        animals[i]->makeSound();
    }
    for (int i = size / 2; i < size; ++i)
    {
        animals[i] = new Cat();
        Cat *cat = dynamic_cast<Cat*>(animals[i]);
        if (cat)
            cat->setBrainIdea(i, "cat cat");
        animals[i]->makeSound();
    }
    for (int i = 0; i < size / 2; i++)
    {
        Dog *dog = dynamic_cast<Dog*> (animals[i]);
        if (dog)
            std::cout << "Dog ideas : " << dog->getBrainIdea(i) << std::endl;
    }
    for (int i = size / 2; i < size; i++)
    {
        Cat *cat = dynamic_cast<Cat*> (animals[i]);
        if(cat)
            std::cout << "cat ideas : " << cat->getBrainIdea(i) << std::endl;
    }

    Dog *otherDog = new Dog();

    otherDog->setBrainIdea(0, "idea one");
    otherDog->setBrainIdea(1, "idea two");

    Dog copyDog = *otherDog;// cuidado con esto : Dog *copyDog = otherDog copy la direccion del pointer, 
                            //Dog *copyDog = new Dog() copyDog = otherDog se pierde la referecia del pointer creado "fuga de memoria" y solo se mantiene la referencia del original.
                            //*otra manera correcta Dog *copyDog = new Dog(*otherDog);

    std::cout << "otherDog idea: " << otherDog->getBrainIdea(0) << std::endl;
    std::cout << "copyDog idea: " << copyDog.getBrainIdea(0) << std::endl;

    std::cout << "otherDog idea: " << otherDog->getBrainIdea(1) << std::endl;
    std::cout << "copyDog idea: " << copyDog.getBrainIdea(1) << std::endl;

    copyDog.setBrainIdea(0, "other idea");
    std::cout << "otherDog idea: " << otherDog->getBrainIdea(0) << std::endl;
    std::cout << "copyDog idea: " << copyDog.getBrainIdea(0) << std::endl; 
 
    Cat *otherCat = new Cat();

    otherCat->setBrainIdea(0, "idea cat one");
    otherCat->setBrainIdea(1, "idea cat two");

    Cat copyCat = *otherCat;

    std::cout << "otherCat idea: " << otherCat->getBrainIdea(0) << std::endl;
    std::cout << "copyCat idea: " << copyCat.getBrainIdea(0) << std::endl;

    std::cout << "otherCat idea: " << otherCat->getBrainIdea(1) << std::endl;
    std::cout << "copyCat idea: " << copyCat.getBrainIdea(1) << std::endl;

    for (int i = 0; i < size; ++i) 
        delete animals[i];
    delete otherDog;
    delete otherCat;
    return 0;
}