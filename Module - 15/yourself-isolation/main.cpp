#include <iostream>

int people;
int personPerFloor;
bool build[5];

int totalPeople(int floors) {
        std::cout << "Enter how much people live in house:" << std::endl;
        do {
            std::cin >> people;
            if (people % floors == 0 && people > 0) return people;
            std::cout << "Incorrect value, must be multiples: " << floors << std::endl;
        } while (true);
};

int peoplePerFloor(int iPeople, int floors){
    std::cout << "Enter how much persons per floor:" << std::endl;
    do {
        std::cin >> personPerFloor;
        if (personPerFloor > 0 && personPerFloor <= people && iPeople % personPerFloor == 0)
            return personPerFloor;
        std::cout << "Incorrect value!" << " We think that need "
            << iPeople / floors << " persons per floor." << std::endl;
    } while (true);
}

int calcInsulation (int people, int personFloor){
    return ((personFloor * 100) / people);
}

int main() {
    int houseFloors = sizeof(build)/sizeof(build[0]);
    int iPeople = totalPeople(houseFloors); // ask user how much people in the build
    int iPersonFloor = peoplePerFloor(iPeople, houseFloors);//ask user how much people at each floor
    std::cout << "Persons on insulation: " << calcInsulation(iPeople, iPersonFloor) << std::endl;
    return 0;
}
