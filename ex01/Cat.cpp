#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), brain(new Brain()) {
	std::cout << "[Cat] default constructed" << std::endl;
}
Cat::Cat(const Cat &o) : Animal(o), brain(new Brain(*o.brain)) {
	std::cout << "[Cat] copy constructed" << std::endl;
}
Cat &Cat::operator=(const Cat &o) {
	if (this!=&o){
		Animal::operator=(o);
		delete brain;
		brain=new Brain(*o.brain);
	}
	return *this;
}
Cat::~Cat() {
	delete brain;
	std::cout << "[Cat] destroyed" << std::endl;
}
void Cat::makeSound() const { std::cout << "[Cat] Meow" << std::endl; }
void Cat::setIdea(int i, const std::string &idea) { brain->setIdea(i, idea); }
std::string Cat::getIdea(int i) const { return brain->getIdea(i); }
