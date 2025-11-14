#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
    std::cout << "[Dog] default constructed" << std::endl;
}

Dog::Dog(const Dog &o) : Animal(o) {
    std::cout << "[Dog] copy constructed" << std::endl;
}

Dog &Dog::operator=(const Dog &o) {
    if (this != &o) {
        Animal::operator=(o);
        std::cout << "[Dog] copy assigned" << std::endl;
    }
    return *this;
}

Dog::~Dog() { std::cout << "[Dog] destroyed" << std::endl; }

void Dog::makeSound() const { std::cout << "[Dog] Woof!" << std::endl; }
