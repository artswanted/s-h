#include <iostream>
#include <string>
#include <vector>

enum list_t {
    SWIM = 0,
    DANCE,
    COUNT
};

class Talante
{
public:
    virtual void isTalante() = 0;
};

class Swimming : virtual public Talante
{
public:
    virtual void isTalante() {
        std::cout << "It can swim." << std::endl;
    }
};

class Dancing : virtual public Talante
{
public:
    virtual void isTalante() {
        std::cout << "It can dance." << std::endl;
    }
};

class Counting : virtual public Talante
{
public:
    virtual void isTalante() {
        std::cout << "It can count." << std::endl;
    }
};

class Dog
{
public:
    Dog(std::string _name, bool swim, bool dance, bool count)
    {
        name = _name;
    }
    void dogName() {
        std::cout << name;
    }
    std::string getName() {
        return name;
    }
    void talanteList(int iType, bool bTalant)
    {
        if (iType == SWIM) swim = bTalant;
        else if (iType == DANCE) dance = bTalant;
        else if (iType == COUNT) count = bTalant;     
    }

    void show_talantes() {
        Talante* s = new Swimming();
        Talante* d = new Dancing();
        Talante* c = new Counting();

        std::cout << swim << dance << count;

        if (swim) {
            s->isTalante();
        }
        if (dance) {
            d->isTalante();
        }
        if (count) {
            c->isTalante();
        }
    }
protected:
    std::string name;
    bool swim;
    bool dance;
    bool count;
};

int main() {
    std::vector<class Dog> dogs;
    Dog dog1("Steve", false, false, false);
    dogs.push_back(dog1);
    Dog dog2("Robert", false, false, false);
    dogs.push_back(dog2);

    for (int i = 0; i < dogs.size(); i++)
    {
        int answer;
        std::cout << dogs[i].getName() << " is can swim?" << std::endl;
        std::cout << "Write 0 for No or 1 for Yes" << std::endl;
        std::cin >> answer;
        dogs[i].talanteList(0, (bool)answer);
        std::cout << dogs[i].getName() << " is can dance?" << std::endl;
        std::cout << "Write 0 for No or 1 for Yes" << std::endl;
        std::cin >> answer;
        dogs[i].talanteList(1, (bool)answer);
        std::cout << dogs[i].getName() << " is can count?" << std::endl;
        std::cout << "Write 0 for No or 1 for Yes" << std::endl;
        std::cin >> answer;
        dogs[i].talanteList(2, (bool)answer);
        std::cout << "IM HERE\n";
    }

    for (int p = 0; p < dogs.size(); p++) {
        std::cout << "This is " << dogs[p].getName() << " and it has some talents:" << std::endl;
        dogs[p].show_talantes();
    }
    return 0;
}