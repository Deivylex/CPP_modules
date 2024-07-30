#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"


class	Phonebook
{
	public:
	Phonebook() : currentSize(0), nextIndex(0) {}

    void add() 
	{
        if (currentSize < maxContacts) 
		{
            Contact contact;
            std::string input;

            std::cout << "Enter first name: ";
            std::cin >> input;
            contact.setFirstName(input);

			std::cout << "Enter last name: ";
            std::cin >> input;
            contact.setLastName(input);

            std::cout << "Enter nickname: ";
            std::cin >> input;
            contact.setNickname(input);

            std::cout << "Enter phone number: ";
            std::cin >> input;
            contact.setPhoneNumber(input);

            std::cout << "Enter darkest secret: ";
            std::cin >> input;
            contact.setDarkestSecret(input);

			contacts[nextIndex] = contact;
            nextIndex = (nextIndex + 1) % maxContacts;
            if (currentSize < maxContacts) currentSize++;
		}  
	}

    void search() const 
    {
        std::cout << std::setw(10) << std::right << "Index" << '|'
                  << std::setw(10) << std::right << "First Name" << '|'
                  << std::setw(10) << std::right << "Last Name" << '|'
                  << std::setw(10) << std::right << "Nickname" << std::endl;

        for (int i = 0; i < currentSize; ++i) 
        {
            std::cout << std::setw(10) << std::right << i << '|'
                      << std::setw(10) << std::right << truncate(contacts[i].getFirstName(), 10) << '|'
                      << std::setw(10) << std::right << truncate(contacts[i].getLastName(), 10) << '|'
                      << std::setw(10) << std::right << truncate(contacts[i].getNickname(), 10) << std::endl;
        }

        int index;
        std::cout << "Enter index to display details: ";
        std::cin >> index;
        std::cin.ignore(); 

        if (index >= 0 && index < currentSize) 
        {
            contacts[index].display();
        } 
        else 
        {
            std::cout << "\033[1;31m" << "Invalid index." << std::endl << "\033[1;34m";
        }
    }
    
	private:
    static const int maxContacts = 8;
    Contact contacts[maxContacts];
    int currentSize;
    int nextIndex;
};

#endif