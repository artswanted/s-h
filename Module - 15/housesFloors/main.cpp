#include <iostream>

bool structure1[3];// fitness center
bool structure2[6];//hotel
bool structure3[20];//office center
bool structure4[40];//people house
int totalBuilding = 4;
int avarageFloors = 0;

int main() {
    std::cout << "Hello, structure calculator!" << std::endl;
    avarageFloors = (sizeof(structure1)/sizeof(structure1[0]) + sizeof(structure2)/sizeof(structure2[0])
            + sizeof(structure3)/sizeof(structure3[0])
            + sizeof(structure4)/sizeof(structure4[0])) / totalBuilding;
    std::cout << "The avarage floors in your quarter " << avarageFloors << std::endl;

    return 0;
}
