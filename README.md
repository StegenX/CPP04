# CPP04 — Module 04: Subtype Polymorphism, Abstract Classes, and Interfaces

This repository contains my solutions to the C++ Module 04 exercises (ex00..ex03). Each exercise is self-contained in its own folder and includes a Makefile that builds a small test program demonstrating the required features: polymorphism, abstract classes, deep copy semantics, and interface usage.

---

## Repository layout

- ex00/  — Exercise 00: simple `Animal`, `Dog`, `Cat` polymorphism and a `WrongAnimal` demonstration
- ex01/  — Exercise 01: `Brain` class, deep copy tests, `Dog` and `Cat` own a `Brain*` (dynamic allocation)
- ex02/  — Exercise 02: (not modified in this repo snapshot)
- ex03/  — Exercise 03: `AMateria`/`Ice`/`Cure`, `ICharacter`, `IMateriaSource`, `MateriaSource`, `Character`

Each exercise folder contains:
- `.cpp` and `.hpp` files that implement the required classes
- a `main.cpp` with tests/demos
- a `Makefile` that builds the exercise binary

---

## Build & run

Each exercise has an independent `Makefile`. To build and run an exercise, open a terminal and run:

```zsh
cd exNN        # replace NN with 00, 01, 02, 03
make           # or make all
./exNN         # runs the produced binary (name matches folder for ex00/ex01/ex03)
```

To do a clean rebuild:

```zsh
make re        # fclean + all
```

If you prefer a single command from the repository root you can run, for example:

```zsh
( cd ex01 && make re && ./ex01 )
```

---

## What I implemented / notable points

- ex00:
  - `Animal` base class with virtual `makeSound()` and virtual destructor
  - `Dog` and `Cat` override `makeSound()` and set their `type`
  - `WrongAnimal`/`WrongCat` to demonstrate the effect of non-virtual functions
  - tests exercise polymorphism and arrays of base pointers

- ex01:
  - Implemented `Brain` containing `std::string ideas[100]`
  - `Dog`/`Cat` own a `Brain*` allocated with `new` in their constructors and deleted in destructors
  - Copy constructor and assignment operator for `Dog`/`Cat` create deep copies of `Brain`
  - `main.cpp` includes tests that show deep copies are independent and that deleting through `Animal*` calls appropriate destructors

- ex03:
  - Implemented `AMateria` (abstract), `Ice`, `Cure` with `clone()` and `use()` semantics
  - Implemented `ICharacter`, `Character`, `IMateriaSource`, `MateriaSource`
  - All classes follow canonical form (default ctor, copy ctor, copy assignment, destructor) where applicable
  - `use()` methods still print their in-universe messages (healing, ice bolt)

Notes:
- I removed noisy constructor/destructor debug printing in later exercises to keep output focused on required behaviors. The tests still produce important behavioral output (for example, `use()` messages).
- Filenames and class names follow the required naming conventions (UpperCamelCase class names and corresponding `ClassName.hpp` / `ClassName.cpp` files).

---

## Testing & memory checks

- The `main.cpp` in each exercise contains several tests (subject example plus extra cases). Check output by running the binary.

- To check for memory leaks, run Valgrind (Linux/macOS with Valgrind installed):

```zsh
cd ex01
valgrind --leak-check=full --show-leak-kinds=all ./ex01
```

Expectations:
- No reachable memory leaks when programs are correctly deleting allocated resources (Brains, Materia, Character inventories, etc.)
- Deep copy tests should show that modifying the source object's `ideas` does not affect the copied object.

---

## Conventions & requirements followed

- Code is written targeting `-std=c++98` and compiled with `-Wall -Wextra -Werror` (Makefiles include these flags).
- Class names and file names follow the UpperCamelCase / ClassName.hpp conventions described in the subject.
- All output messages required by the exercises (for `use()` and test verification) end with a newline and are printed to `stdout`.
- Classes implement the Rule of Three where necessary (destructor, copy constructor, copy assignment).
