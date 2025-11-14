#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    std::cout << "[WrongAnimal] default constructed" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &t) : type(t) {
    std::cout << "[WrongAnimal] constructed with type '" << t << "'" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &o) : type(o.type) {
    std::cout << "[WrongAnimal] copy constructed" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &o) {
    if (this != &o) type = o.type;
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "[WrongAnimal] destroyed" << std::endl;
}

void WrongAnimal::makeSound() const {
    std::cout << "[WrongAnimal] ... (generic wrong sound)" << std::endl;
}

std::string WrongAnimal::getType() const { return type; }
