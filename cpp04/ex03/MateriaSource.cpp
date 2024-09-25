#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        _temple[i] = nullptr;
    std::cout << "MateriaSource constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
    for (int i = 0; i < 4; i++)
    {
        if ( other._temple[i] )
            _temple[i] = other._temple[i]->clone();
        else
            _temple[i] = nullptr; 
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    if (this != &other)
    {
        for(int i = 0; i < 4; i++)
        {
            if (_temple[i])
            {
                delete _temple[i];
                _temple[i] = nullptr;
            }
        }
        for (int i = 0; i < 4; i++)
        {
            if ( other._temple[i] )
                _temple[i] = other._temple[i]->clone();
            else
                _temple[i] = nullptr; 
        }
    }
    return (*this);
}

MateriaSource::~MateriaSource() 
{
    for(int i = 0; i < 4; i++)
    {
        if (_temple[i])
        {
            delete _temple[i];
            _temple[i] = nullptr;
        }
    }
    std::cout << "MateriaSource destructor called" << std::endl; 
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (!m)
        return ;
    for( int i= 0; i < 4; i++)
    {
        if (!_temple[i])
        {
            _temple[i] = m;
            std::cout << "Learned a new Materia " << m->getType() << std::endl;
            return ;
        }
    }
    std::cout << "No space to learn more Materias!" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (type == _temple[i]->getType() && _temple[i])
        {
            std::cout << "Creating this new Materia " << type << std::endl;
            return _temple[i]->clone();
        }
    }
    std::cout << "this Materia is unknown " << type << std::endl;
    return 0;
}