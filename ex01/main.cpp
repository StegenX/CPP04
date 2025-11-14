#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    std::cout << "==== Polymorphic array test (construction, sounds, destruction) ====" << std::endl;
    const int N = 6;
    Animal* zoo[N];
    for (int i=0;i<N;i++) zoo[i] = (i%2)? static_cast<Animal*>(new Cat()) : static_cast<Animal*>(new Dog());
    for (int i=0;i<N;i++) zoo[i]->makeSound();
    for (int i=0;i<N;i++) delete zoo[i];

    std::cout << "\n==== Subject sanity check ====" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;
    delete i;

    std::cout << "\n==== Deep copy tests (Dog) ====" << std::endl;
    Dog a; a.setIdea(0,"bone");
    Dog b=a;
    a.setIdea(0,"stick");
    std::cout << "a[0]=" << a.getIdea(0) << std::endl;
    std::cout << "b[0]=" << b.getIdea(0) << std::endl;

    std::cout << "\n==== Deep copy tests (Cat assignment) ====" << std::endl;
    Cat c1; c1.setIdea(1, "nap");
    Cat c2; c2 = c1;
    c1.setIdea(1, "hunt");
    std::cout << "c1[1]=" << c1.getIdea(1) << std::endl;
    std::cout << "c2[1]=" << c2.getIdea(1) << std::endl;

    return 0;
}