#include "phonebook.hpp"

PhoneBook::PhoneBook() : currentSize(0), nextIndex(0) {}

void PhoneBook::add() 
{
        if (currentSize < maxContacts) 
		{
            Contact contact;
            std::string input;

            std::cout << "Enter first name: ";
            std::getline(std::cin, input);
            if (std::cin.eof())
                throw std::runtime_error("Error");
            contact.setFirstName(input);

			std::cout << "Enter last name: ";
            std::getline(std::cin, input);
            if (std::cin.eof())
                throw std::runtime_error("Error");
            contact.setLastName(input);

            std::cout << "Enter nickname: ";
            std::getline(std::cin, input);
            if (std::cin.eof())
                throw std::runtime_error("Error");
            contact.setNickname(input);

            std::cout << "Enter phone number: ";
            std::getline(std::cin, input);
            if (std::cin.eof())
                throw std::runtime_error("Error");
            contact.setPhoneNumber(input);

            std::cout << "Enter darkest secret: ";
            std::getline(std::cin, input);
            if (std::cin.eof())
                throw std::runtime_error("Error");
            contact.setDarkestSecret(input);

			contacts[nextIndex] = contact;
            nextIndex = (nextIndex + 1) % maxContacts;
            if (currentSize < maxContacts) currentSize++;
		}  
	}

void PhoneBook::search()
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
        int index = 0;
        std::string input;
        std::cout << "Enter index to display details: ";
        std::getline(std::cin, input); 
        if (std::cin.eof())
            throw std::runtime_error("Error");
        if (input.size() == 1 && !std::isdigit(input[0])) 
        {
            std::cout << "\033[1;31m" << "Invalid input. need to be a number." << "\033[0m" << std::endl << "\033[1;34m";
            return;
        }
        index = std::stoi(input);
        if (index >= 0 && index < currentSize) 
        {
            contacts[index].display();
            index = -1;
        } 
        else
            std::cout << "\033[1;31m" << "Invalid index." << std::endl << "\033[1;34m";
    }