#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private :

	AMateria* _temple[4];

	public :

	MateriaSource();
	MateriaSource(std::string name);
	MateriaSource(const MateriaSource& other);
	MateriaSource& operator=(const MateriaSource& other);
	~MateriaSource();

	void learnMateria(AMateria*) override;
	AMateria* createMateria(std::string const & type) override;
};

#endif