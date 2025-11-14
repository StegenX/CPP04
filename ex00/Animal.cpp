#include "Animal.hpp"

Animal::Animal() : type("Animal") {
    std::cout << "[Animal] default constructed" << std::endl;
}

Animal::Animal(const std::string &t) : type(t) {
    std::cout << "[Animal] constructed with type '" << t << "'" << std::endl;
}

Animal::Animal(const Animal &o) : type(o.type) {
    std::cout << "[Animal] copy constructed" << std::endl;
}

Animal &Animal::operator=(const Animal &o) { 
    if (this != &o) 
        type = o.type; 
    return *this;
}

Animal::~Animal() {
    std::cout << "[Animal] destroyed" << std::endl;
}

void Animal::makeSound() const { 
    std::cout << "[Animal] ... (generic sound)" << std::endl;
}

std::string Animal::getType() const { return type; }