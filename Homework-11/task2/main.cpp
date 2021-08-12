#include <iostream>
#include <vector>
#include <time.h>

struct village {
    int area = 0;
    int house = 0;
    int garage = 0;
    int bath = 0;
    int bard = 0;
};

struct houseInfo {
    int floor = 0;
    int room = 0;
    int bake = 0;
    int floorSize = 0;
};

struct roomInfo {

    enum TypeRoom {
        ROOM_BEDROOM = 1,
        ROOM_KITCHEN = 2,
        ROOM_BATHROOM = 3,
        ROOM_NURCERY = 4,
        ROOM_LIVINGROOM = 5
    };

    double roomSize = 0;
    int roomEnctype = 0;
};



int main() {
    srand(time(NULL));
    std::vector <village> villageArray = {};
    std::vector <houseInfo> houseArray = {};
    std::vector <roomInfo> roomArray = {};
    std::cout << "Welcome, welcome to city 17. It's the best city left!" << std::endl << std::endl;
    village area_gen;
    houseInfo house_gen;
    roomInfo room_gen;

    area_gen.area = rand() % 10 +1;

    for (int i = 0; i < area_gen.area; i++){
        area_gen.house = rand() % 3 + 1;
        area_gen.garage = rand() % 2;
        area_gen.bath = rand() % 2;
        area_gen.bard = rand() % 2;
        villageArray.push_back(area_gen);

        for (int j = 0; j < area_gen.house; j++){
            house_gen.floor = rand() % 3 + 1;
            for (int l = 0; l < house_gen.floor; l++){
                house_gen.room = rand() % 4 + 2;
                house_gen.floorSize = rand() % 5 + 3;
                house_gen.bake = rand() % 2;

                for(int q = 0; q < house_gen.room; q++){
                    room_gen.roomEnctype = rand() % 5 + 1;
                    room_gen.roomSize = rand() % 20 + 5;
                    roomArray.push_back(room_gen);
                }
            }
            houseArray.push_back(house_gen);
        }
    }

    std::cout << "Village size " << villageArray[0].area << " areas." << std::endl << std::endl;
    for (int i = 0; i < villageArray.size(); i++){
        std::cout << "----- Area No." << i+1 << "-------------------------" << std::endl;
        std::cout << "Houses: " << villageArray[i].house << std::endl;
        std::cout << "Garage: " << villageArray[i].garage << std::endl;
        std::cout << "Bath: " << villageArray[i].bath << std::endl;
        std::cout << "Bard: " << villageArray[i].bard << std::endl << std::endl;

        for (int j = 0; j < villageArray[i].house; j++) {
            std::cout << "Area No." << i+1 << ", House No." << j+1 << std::endl;
            std::cout << "Floor No.: " << houseArray[j].floor << std::endl;
            std::cout << "Floor Size: " << houseArray[j].floorSize << std::endl;
            std::cout << "Room: " << houseArray[j].room << std::endl;
            std::cout << "Bake: " << houseArray[j].bake << std::endl << std::endl;

            for (int h = 0; h < houseArray[j].room; h++) {
                std::cout << "Area No." << i+1 << ", House No." << j+1 << ", Room No." << h+1 << std::endl;
                std::cout << "Room size: " << roomArray[h].roomSize << std::endl;
                switch (roomArray[h].roomEnctype) {
                    case room_gen.ROOM_BEDROOM:{
                        std::cout << "Room type: Bedroom" << std::endl << std::endl;
                    }break;
                    case room_gen.ROOM_KITCHEN:{
                        std::cout << "Room type: Kitchen" << std::endl << std::endl;
                    }break;
                    case room_gen.ROOM_LIVINGROOM:{
                        std::cout << "Room type: Living room" << std::endl << std::endl;
                    }break;
                    case room_gen.ROOM_NURCERY:{
                        std::cout << "Room type: Nurcery" << std::endl << std::endl;
                    }break;
                    case room_gen.ROOM_BATHROOM:{
                        std::cout << "Room type: Bathroom" << std::endl << std::endl;
                    }break;
                }
            }
        }
    }



    return 0;
}