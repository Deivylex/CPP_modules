#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>

std::string truncate(const std::string &str, size_t width);

class Contact {
public:
    Contact();
    ~Contact();

    void setFirstName(const std::string &first_name);
    void setLastName(const std::string &last_name);
    void setNickname(const std::string &nickname);
    void setPhoneNumber(const std::string &phone_number);
    void setDarkestSecret(const std::string &darknes_secret);

    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const;

    void display() const;

private:
    std::string first_name;
    std::string last_name;
    std::string nick_name;
    std::string phone_number;
    std::string darknes_secret;
};

#endif
