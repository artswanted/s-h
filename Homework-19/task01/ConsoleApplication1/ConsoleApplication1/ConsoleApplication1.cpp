#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Talents {
public:
    virtual void show_talent() = 0;
    virtual ~Talents() = default;
};

class Dog {
private:
    std::string name = "Pet";
    std::vector<Talents*> abilities;

public:
    explicit Dog(const std::string& name);
    virtual ~Dog();

    void clearAbilities();
    bool addAbility(Talents* ability);
    void show_talent();
};

class Dancing : virtual public Talents {
public:
    void show_talent() override;
};

class Counting : virtual public Talents {
public:
    void show_talent() override;
};

Dog::Dog(const std::string& name) {
    this->name = name;
}

class Swimming : virtual public Talents {
public:
    void show_talent() override;
};


void Dog::clearAbilities() {
    if (!abilities.empty())
    {
        for (auto talent : abilities) {
            delete talent;
        }
        abilities.clear();
    }
}

bool Dog::addAbility(Talents* ability) {
    if (ability != nullptr) {
        abilities.push_back(ability);
        return true;
    }
    return false;
}

void Dog::show_talent() {
    std::cout << "This dog has name: " << name << " and it has a some talents:\n";
    if (abilities.empty()) {
        std::cout << "Sorry, your dog is stupid";
    }
    else {
        for (auto& ability : abilities) {
            ability->show_talent();
        }
    }
}

Dog::~Dog() {
    clearAbilities();
    std::cout << "Doggy died" << std::endl;
}

void Dancing::show_talent() {
    std::cout << "It can dance" << std::endl;
}

void Counting::show_talent() {
    std::cout << "It can count" << std::endl;
}

void Swimming::show_talent() {
    std::cout << "It can swim" << std::endl;
}

int main() {
    Dog dog("Doggy");

    dog.addAbility(new Swimming());
    dog.addAbility(new Dancing());
    dog.show_talent();

    cout << endl;
    dog.clearAbilities();
    dog.show_talent();
    cout << endl;

    cout << endl;
    dog.addAbility(new Counting());
    dog.addAbility(new Swimming());
    dog.show_talent();
    cout << endl;
}