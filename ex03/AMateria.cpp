#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria() : type("")
{
}

AMateria::AMateria(const std::string &t) : type(t)
{
}

AMateria::AMateria(const AMateria &o) : type(o.type)
{
}

AMateria &AMateria::operator=(const AMateria &o)
{
	if (this != &o)
		type = o.type;
	return *this;
}

AMateria::~AMateria()
{
}

const std::string &AMateria::getType() const
{
	return type;
}

void AMateria::use(ICharacter &target)
{
	(void)target;
}