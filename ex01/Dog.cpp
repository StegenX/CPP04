#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), brain(new Brain()) {
	std::cout << "[Dog] default constructed" << std::endl;
}
Dog::Dog(const Dog &o) : Animal(o), brain(new Brain(*o.brain)) {
	std::cout << "[Dog] copy constructed" << std::endl;
}
Dog &Dog::operator=(const Dog &o) {
	if (this!=&o){
		Animal::operator=(o);
		delete brain;
		brain=new Brain(*o.brain);
	}
	return *this;
}
Dog::~Dog() {
	delete brain;
	std::cout << "[Dog] destroyed" << std::endl;
}
void Dog::makeSound() const { std::cout << "[Dog] Woof" << std::endl; }
void Dog::setIdea(int i, const std::string &idea) { brain->setIdea(i, idea); }
std::string Dog::getIdea(int i) const { return brain->getIdea(i); }
