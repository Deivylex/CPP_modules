#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "contact.hpp"

class	PhoneBook
{
	public:
    
	PhoneBook();

    void add();

    void search();

	private:
    static const int maxContacts = 8;
    Contact contacts[maxContacts];
    int currentSize;
    int nextIndex;
};

#endif