#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "IMateriaSource.hpp"
#include "ICharacter.hpp"


int main()
{
    IMateriaSource* src = new MateriaSource(); //muestra error aqui
    src->learnMateria(new Ice());
    src->learnMateria(new Cure()); //muestra error aqui
    ICharacter* me = new Character("me");//muestra error aqui
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");//muestra error aqui
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;
    return 0;
}