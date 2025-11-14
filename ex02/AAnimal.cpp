#include "AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal") {
	std::cout << "[AAnimal] default constructed" << std::endl;
}

AAnimal::AAnimal(const std::string &t) : type(t) {
	std::cout << "[AAnimal] constructed with type '" << t << "'" << std::endl;
}

AAnimal::AAnimal(const AAnimal &o) : type(o.type) {
	std::cout << "[AAnimal] copy constructed" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &o) {
	if (this != &o)
		type = o.type;
	return *this;
}

AAnimal::~AAnimal() {
	std::cout << "[AAnimal] destroyed" << std::endl;
}

std::string AAnimal::getType() const { return type; }