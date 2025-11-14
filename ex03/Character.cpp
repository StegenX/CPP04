#include "Character.hpp"

Character::Character() : name("")
{
    for (int i = 0; i < 4; ++i)
        inventory[i] = 0;
}

Character::Character(const std::string &n) : name(n)
{
    for (int i = 0; i < 4; ++i)
        inventory[i] = 0;
}

Character::Character(const Character &o) : name(o.name)
{
    for (int i = 0; i < 4; ++i)
        inventory[i] = o.inventory[i] ? o.inventory[i]->clone() : 0;
}

Character &Character::operator=(const Character &o)
{
    if (this != &o)
    {
        name = o.name;
        for (int i = 0; i < 4; ++i)
        {
            delete inventory[i];
            inventory[i] = o.inventory[i] ? o.inventory[i]->clone() : 0;
        }
    }
    return *this;
}

Character::~Character()
{
    for (int i = 0; i < 4; ++i)
        delete inventory[i];
}

const std::string &Character::getName() const
{
    return name;
}

void Character::equip(AMateria *m)
{
    if (!m)
        return;

    for (int i = 0; i < 4; ++i)
    {
        if (!inventory[i])
        {
            inventory[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4)
        inventory[idx] = 0;
}

void Character::use(int idx, ICharacter &target)
{
    if (idx >= 0 && idx < 4 && inventory[idx])
        inventory[idx]->use(target);
}