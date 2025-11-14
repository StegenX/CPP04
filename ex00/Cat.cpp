#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
    std::cout << "[Cat] default constructed" << std::endl;
}

Cat::Cat(const Cat &o) : Animal(o) {
    std::cout << "[Cat] copy constructed" << std::endl;
}

Cat &Cat::operator=(const Cat &o) {
    if (this != &o) {
        Animal::operator=(o);
        std::cout << "[Cat] copy assigned" << std::endl;
    }
    return *this;
}

Cat::~Cat() { std::cout << "[Cat] destroyed" << std::endl; }

void Cat::makeSound() const { std::cout << "[Cat] Meow!" << std::endl; }
