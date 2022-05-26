#include <iostream>
#include <string>

class Animal
{
public:
    virtual std::string voice() = 0;
};

class Dog : public Animal
{
public:
    virtual std::string voice()
    {
        return "Bark";
    }
};

class Cat : public Animal
{
public:
    virtual std::string voice()
    {
        return "Meow";
    }
};

void meeting(Animal* a, Animal* b)
{
    std::string answer = a->voice() + b->voice();
    if (answer == "BarkBark")
        std::cout << "Woof-Woof" << std::endl;
    else if (answer == "BarkMeow")
        std::cout << "Bark Meow" << std::endl;
    else if (answer == "MeowBark")
        std::cout << "Meow Bark" << std::endl;
    else if (answer == "MeowMeow")
        std::cout << "Purr Purr" << std::endl;
}



int main() {
    Animal* a = new Dog();
    Animal* b = new Cat();
    meeting(a, b);
    meeting(a, a);
    meeting(b, b);
    meeting(b, a);
}