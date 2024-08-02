#include "phonebook.hpp"

std::string truncate(const std::string &str, size_t width) 
{
    if (str.size() > width) 
    {
        return str.substr(0, width - 1) + '.';
    } 
    else 
    {
        return str;
    }
}

Contact::~Contact(){}

Contact::Contact() : first_name(""), last_name(""), nick_name(""), phone_number(""), darknes_secret("") {}

void Contact::setFirstName(const std::string &first_name) { this->first_name = first_name; }
void Contact::setLastName(const std::string &last_name) { this->last_name = last_name; }
void Contact::setNickname(const std::string &nickname) { this->nick_name = nickname; }
void Contact::setPhoneNumber(const std::string &phone_number) { this->phone_number = phone_number; }
void Contact::setDarkestSecret(const std::string &darknes_secret) { this->darknes_secret = darknes_secret; }

std::string Contact::getFirstName() const { return first_name; }
std::string Contact::getLastName() const { return last_name; }
std::string Contact::getNickname() const { return nick_name; }
std::string Contact::getPhoneNumber() const { return phone_number; }
std::string Contact::getDarkestSecret() const { return darknes_secret; }

void Contact::display() const 
{
    std::cout << "First Name: " << first_name << std::endl;
    std::cout << "Last Name: " << last_name << std::endl;
    std::cout << "Nickname: " << nick_name << std::endl;
    std::cout << "Phone Number: " << phone_number << std::endl;
    std::cout << "Darkest Secret: " << darknes_secret << std::endl;
}