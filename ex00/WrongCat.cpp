#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") { 
    std::cout << "[WrongCat] default constructed" << std::endl;
}
WrongCat::WrongCat(const WrongCat &o) : WrongAnimal(o) { 
    std::cout << "[WrongCat] copy constructed" << std::endl;
}
WrongCat &WrongCat::operator=(const WrongCat &o) {
    if (this != &o) {
        WrongAnimal::operator=(o);
        std::cout << "[WrongCat] copy assigned" << std::endl;
    }
    return *this;
}
WrongCat::~WrongCat() { 
    std::cout << "[WrongCat] destroyed" << std::endl; 
}
void WrongCat::makeSound() const { 
    std::cout << "[WrongCat] Meow? (but will be hidden if called via WrongAnimal*)" << std::endl; 
}
