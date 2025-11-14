#include "Dog.hpp"
#include "Cat.hpp"
int main() {
    const AAnimal* a = new Dog();
    const AAnimal* b = new Cat();
    a->makeSound();
    b->makeSound();
    delete a;
    delete b;
    Dog d; d.setIdea(0,"bone");
    Dog e=d; d.setIdea(0,"stick");
    std::cout << d.getIdea(0) << std::endl;
    std::cout << e.getIdea(0) << std::endl;
    return 0;
}