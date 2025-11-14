#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; ++i)
        slots[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource &o)
{
    for (int i = 0; i < 4; ++i)
        slots[i] = o.slots[i] ? o.slots[i]->clone() : 0;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &o)
{
    if (this != &o)
    {
        for (int i = 0; i < 4; ++i)
        {
            delete slots[i];
            slots[i] = o.slots[i] ? o.slots[i]->clone() : 0;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; ++i)
        delete slots[i];
}

void MateriaSource::learnMateria(AMateria *m)
{
    if (!m)
        return;

    for (int i = 0; i < 4; ++i)
    {
        if (!slots[i])
        {
            slots[i] = m;
            return;
        }
    }
}

AMateria *MateriaSource::createMateria(const std::string &type)
{
    for (int i = 0; i < 4; ++i)
    {
        if (slots[i] && slots[i]->getType() == type)
            return slots[i]->clone();
    }
    return 0;
}