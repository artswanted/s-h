#include <iostream>
#include <string>

class Animal
{
public:
    virtual void voice() = 0;
};

class Dog : public Animal
{
public:
    virtual void voice()
    {
        std::string voice = "Bark";
    }
};

class Cat : public Animal
{
public:
    virtual void voice()
    {
        std::string voice = "Bark";
    }
};

void meeting(Animal* a, Animal* b)
{
    if (a->voice() == "Bark")
}



int main() {
    Animal* a = new Dog();
    Animal* b = new Cat();
    meeting(a, b);
    meeting(a, a);
    meeting(b, b);
    meeting(b, a);
}