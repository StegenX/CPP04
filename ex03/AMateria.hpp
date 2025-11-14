#ifndef AMATERIA_HPP
#define AMATERIA_HPP
#include <string>
#include <iostream>
class ICharacter;
class AMateria {
protected:
    std::string type;
public:
    AMateria(const std::string &type);
    AMateria();
    AMateria(const AMateria &other);
    AMateria &operator=(const AMateria &other);
    virtual ~AMateria();
    const std::string &getType() const;
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter &target);
};
#endif