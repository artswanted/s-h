#include <iostream>
#include <string>

class Animal
{
public:
    virtual void voice() = 0;
};

class Dog : virtual public Animal
{
public:
    virtual void voice()
    {
            std::cout << "Bark! " << std::endl;
    }
};

class Cat : virtual public Animal
{
public:
    virtual void voice()
    {
            std::cout << "Meow! " << std::endl;
    }
};

class CatDog : virtual public Cat, virtual public Dog
{
public:
    virtual void voice()
    {
        std::cout << "BarkMeow! " << std::endl;
    }
};



int main() {
    std::cout << "test";
}