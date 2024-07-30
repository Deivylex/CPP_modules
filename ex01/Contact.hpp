#ifndef CONTACT_HPP

# define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>

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

class Contact {
public:
    Contact() : first_name(""), last_name(""), nick_name(""), phone_number(""), darknes_secret("") {}

    void setFirstName(const std::string &first_name) { this->first_name = first_name; }
    void setLastName(const std::string &last_name) { this->last_name = last_name; }
    void setNickname(const std::string &nickname) { this->nick_name = nickname; }
    void setPhoneNumber(const std::string &phone_number) { this->phone_number = phone_number; }
    void setDarkestSecret(const std::string &darknes_secret) { this->darknes_secret = darknes_secret; }

    std::string getFirstName() const { return first_name; }
    std::string getLastName() const { return last_name; }
    std::string getNickname() const { return nick_name; }
    std::string getPhoneNumber() const { return phone_number; }
    std::string getDarkestSecret() const { return darknes_secret; }

    void display() const 
    {
        std::cout << "First Name: " << first_name << std::endl;
        std::cout << "Last Name: " << last_name << std::endl;
        std::cout << "Nickname: " << nick_name << std::endl;
        std::cout << "Phone Number: " << phone_number << std::endl;
        std::cout << "Darkest Secret: " << darknes_secret << std::endl;
    }

private:
		std::string	first_name;
		std::string	last_name;
		std::string	nick_name;
		std::string	phone_number;
		std::string	darknes_secret;
};

#endif