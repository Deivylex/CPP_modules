#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "IMateriaSource.hpp"
#include "ICharacter.hpp"

int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp); // equip ice in slot 0

    tmp = src->createMateria("cure");
    me->equip(tmp); // equip cure in slot 1

    // Test: Attempt to create a Materia with an unknown type
    tmp = src->createMateria("....");
    if (tmp == nullptr)
        std::cout << "Invalid Materia not equipped\n";

    tmp = src->createMateria("ice");
    me->equip(tmp); // equip another ice in slot 2

    tmp = src->createMateria("cure");
    me->equip(tmp); // equip another cure in slot 3

    // Test: Inventory is full, should not equip more
    tmp = src->createMateria("ice");
    me->equip(tmp); // Should not equip

    ICharacter* bob = new Character("bob");

    // Use all Materias on Bob
    me->use(0, *bob); // Use ice
    me->use(1, *bob); // Use cure
    me->use(2, *bob); // Use ice
    me->use(3, *bob); // Use cure

    // Test: Attempt to use an out-of-bounds index
    me->use(4, *bob); // Invalid index, should not crash or perform action

    // Test: Unequip a Materia and try to use it
    me->unequip(1); // Unequip cure from slot 1
    me->unequip(2);
    me->unequip(5);
    std::cout << "Slot 1 unequipped\n";
    me->use(1, *bob); // Should not do anything since it's unequipped

    // Clean up manually unequipped Materias to avoid memory leaks
    delete tmp;

    // Test: Try equipping after unequipping to verify free slots
    tmp = src->createMateria("cure");
    me->equip(tmp); // This should work since slot 1 is now free

    // Use the newly equipped Materia
    me->use(1, *bob); // Use the new cure

    // Clean up
    delete bob;
    delete me;
    delete src;

    return 0;
}