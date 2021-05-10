#include <iostream>

bool littleShip[4];
bool smallShip[3];
bool mediumShip[2];
bool bigShip[1];

int main() {
    std::cout << "You have " << sizeof(littleShip) / sizeof(littleShip[0]) << " little ships!" << std::endl;
    std::cout << "You have " << sizeof(smallShip) / sizeof(smallShip[0]) << " small ships!" << std::endl;
    std::cout << "You have " << sizeof(mediumShip) / sizeof(mediumShip[0]) << " medium ships!" << std::endl;
    std::cout << "You have " << sizeof(bigShip) / sizeof(bigShip[0]) << " big ships!" << std::endl;
    return 0;
}
