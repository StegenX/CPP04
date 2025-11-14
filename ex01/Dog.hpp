#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public Animal {
private:
    Brain *brain;
public:
    Dog();
    Dog(const Dog &other);
    Dog &operator=(const Dog &other);
    virtual ~Dog();
    virtual void makeSound() const;
    void setIdea(int i, const std::string &idea);
    std::string getIdea(int i) const;
};

#endif
