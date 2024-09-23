#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
    protected :

    std::string ideas[100];

    public :

    Brain();
    Brain(const Brain& other);
    Brain& operator=(const Brain& other);
    ~Brain();

     void setIdeas(int index, const std::string& idea);
    std::string getIdeas(int index);

};

#endif