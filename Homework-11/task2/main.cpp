#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

int totalPieceOfLand;

enum eBuildingsType
        {
    GARAGE = 1,
    BARN,
    BATHHOUSE,
    COUNT_BUILDING_TYPES = 3
        };

enum eRoomsType
        {
    BEDROOM = 1,
    KITCHEN,
    CHILDRENS_ROOM,
    LIVING_ROOM,
    BATHROOM,
    COUNT_ROOM_TYPES = 5
        };

struct SRoom
        {
    eRoomsType type;
    int square = 0;
        };

struct SFloor
        {
    int ceilingHeight = 0;
    std::vector <SRoom> room;
        };

struct SPieceOfLand
        {
    std::string uniqueNumber;

    struct SHouse
            {
        bool chimney = false;
        std::vector <SFloor> floor;
            } house;

    struct SGarage
            {
        bool enable = false;
        int square = 0;
            } garage;

    struct SBarn
            {
        bool enable = false;
        int square = 0;
            } barn;

    struct SBathhouse
            {
        bool enable = false;
        int square = 0;
        bool chimney = false;
            } bathhouse;
        };

bool positiveCheck(std::string& str)
{
    bool error = false;
    for (int i = 0; (i < str.length()) && !error; ++i)
        if (str[i] < '0' || str[i] > '9') return false;

        return true;
}

int enterInt()
{
    std::string tmp;
    do
        std::cin >> tmp;
    while (!positiveCheck(tmp));
    return (std::stoi(tmp));
}

int fillSquare(const std::string& buildingName)
{
    std::cout << "Enter square of your " << buildingName << ": ";

    return (enterInt());
}

char enterYN()
{
    char answer;
    do
        std::cin >> answer;
    while (answer != 'y' && answer != 'n');

    return answer;
}

SFloor fillFloor()
{
    SFloor floor;
    std::cout << "Enter floor height: ";
    floor.ceilingHeight = enterInt();

    std::cout << "Enter count of rooms: ";
    int roomCount = enterInt();
    for (int i = 1; i <= roomCount; ++i)
    {
        std::cout << "Choose one of the types of rooms below for the " << i << " room" << std::endl;
        std::cout << BEDROOM << ". Bedroom;" << std::endl;
        std::cout << KITCHEN << ". Kitchen;" << std::endl;
        std::cout << CHILDRENS_ROOM << ". Childrens room;" << std::endl;
        std::cout << LIVING_ROOM << ". Living room;" << std::endl;
        std::cout << BATHROOM << ". Bathroom;" << std::endl;
        int roomType;
        do
            roomType = enterInt();
        while (roomType < 1 || roomType > COUNT_ROOM_TYPES);

        std::cout << "Enter square this room: ";
        SRoom currentRoom;
        currentRoom.square = enterInt();

        switch (roomType)
        {
            case BEDROOM:
                currentRoom.type = BEDROOM; break;
                case KITCHEN:
                    currentRoom.type = KITCHEN;	break;
                    case CHILDRENS_ROOM:
                        currentRoom.type = CHILDRENS_ROOM; break;
                        case LIVING_ROOM:
                            currentRoom.type = LIVING_ROOM; break;
                            case BATHROOM:
                                currentRoom.type = BATHROOM; break;
        }
        floor.room.push_back(currentRoom);
    }

    return floor;
}

void fillHouse(SPieceOfLand& piece)
{
    std::cout << "Does your house have chimney? (y/n): ";
    if (enterYN() == 'y')	piece.house.chimney = true;
    std::cout << "How many floors on your house? ";
    int floorCount = enterInt();

    for (int i = 1; i <= floorCount; ++i)
    {
        std::cout << "Fill " << i << " floor of " << floorCount << " ~" << std::endl;
        piece.house.floor.push_back(fillFloor());
    }
}

void fillGarage(SPieceOfLand &piece)
{
    piece.garage.enable = true;
    piece.garage.square = fillSquare("garage");
    if (piece.garage.square == 0)
    {
        piece.garage.enable = false;
        std::cout << "Garage wasn't added ~" << std::endl;
    }
    else	std::cout << "Square of your garage was added ~" << std::endl;
}

void fillBarn(SPieceOfLand &piece)
{
    piece.barn.enable = true;
    piece.barn.square = fillSquare("barn");

    if (piece.barn.square == 0)
    {
        piece.barn.enable = false;
        std::cout << "Barn wasn't added ~" << std::endl;
    }
    else
        std::cout << "Square of your barn was added ~" << std::endl;
}

void fillBathhouse(SPieceOfLand &piece)
{
    piece.bathhouse.enable = true;
    piece.bathhouse.square = fillSquare("bathhouse");

    if (piece.bathhouse.square == 0)
    {
        piece.bathhouse.enable = false;
        std::cout << "Bathhouse wasn't added" << std::endl;
    }
    else
    {
        std::cout << "Square of your bathhouse was added" << std::endl << std::endl;
        std::cout << "Does you bathhouse has chimney? (y/n): ";
        if (enterYN() == 'y')
            piece.bathhouse.chimney = true;
    }
}

SPieceOfLand fillPieceOfLand()
{
    SPieceOfLand pieceOfLand;
    std::cout << "Enter unique number of your piece of land: ";
    std::cin >> pieceOfLand.uniqueNumber;

    fillHouse(pieceOfLand);

    bool next = false;
    do
    {
        std::cout << "Do you have some buildings? (y/n): ";

        if (enterYN() == 'y')
        {
            int answer;
            do
            {
                std::cout << "Choose one of this:" << std::endl;
                std::cout << GARAGE << ". Garage;" << std::endl;
                std::cout << BARN << ". Barn;" << std::endl;
                std::cout << BATHHOUSE << ". Bathhouse." << std::endl;
                std::cout << "0. Exit from this piece of land" << std::endl;
                answer = enterInt();
            } while (answer < 0 || answer > COUNT_BUILDING_TYPES);

            switch (answer)
            {
                case GARAGE:
                    fillGarage(pieceOfLand); break;
                    case BARN:
                        fillBarn(pieceOfLand); break;
                        case BATHHOUSE:
                            fillBathhouse(pieceOfLand); break;
                            case 0: next = true; break;
            }
        }
        else next = true;
    }
    while (!next);

    return pieceOfLand;
}

void outResult(std::vector <SPieceOfLand>& piecesOfLand)
{
    int totalSquare = 0;
    int totalBuildings = totalPieceOfLand;
    int totalRooms = 0;
    int totalBedrooms = 0;
    int totalKitchens = 0;
    int totalChildrenRooms = 0;
    int totalLivingRooms = 0;
    int totalBathrooms = 0;

    for (int p = 0; p < totalPieceOfLand; ++p)
    {
        if (piecesOfLand[p].barn.enable)
        {
            totalSquare += piecesOfLand[p].barn.square;
            ++totalBuildings;
        }
        if (piecesOfLand[p].bathhouse.enable)
        {
            totalSquare += piecesOfLand[p].bathhouse.square;
            ++totalBuildings;
        }
        if (piecesOfLand[p].garage.enable)
        {
            totalSquare += piecesOfLand[p].garage.square;
            ++totalBuildings;
        }

        for (int f = 0; f < piecesOfLand[p].house.floor.size(); ++f)
        {
            totalRooms += piecesOfLand[p].house.floor[f].room.size();
            for (int r = 0; r < piecesOfLand[p].house.floor[f].room.size(); ++r)
                switch (piecesOfLand[p].house.floor[f].room[r].type)
                {
                case BEDROOM:
                    ++totalBedrooms; break;
                    case KITCHEN:
                        ++totalKitchens; break;
                        case CHILDRENS_ROOM:
                            ++totalChildrenRooms; break;
                            case LIVING_ROOM:
                                ++totalLivingRooms; break;
                                case BATHROOM:
                                    ++totalBathrooms; break;
                }
        }

    }

    std::cout << "Total count of buildings is  " << totalBuildings << std::endl;
    std::cout << "Total square of buildings is " << totalSquare << std::endl;
    std::cout << "Total count of rooms is " << totalRooms << std::endl;
    std::cout.width(20);
    std::cout << "bedrooms: " << totalBedrooms << std::endl;
    std::cout.width(20);
    std::cout << "kitchens: " << totalKitchens << std::endl;
    std::cout.width(20);
    std::cout << "children rooms: " << totalChildrenRooms << std::endl;
    std::cout.width(20);
    std::cout << "living rooms: " << totalLivingRooms << std::endl;
    std::cout.width(20);
    std::cout << "bathrooms: " << totalBathrooms << std::endl;
}

int main()
{
    std::cout << "Enter total piece of land: ";
    std::cin >> totalPieceOfLand;
    std::vector <SPieceOfLand> piecesOfLand;

    for (int i = 1; i <= totalPieceOfLand; ++i)
    {
        std::cout << "Fill " << i << " piece of land" << std::endl << std::endl;
        piecesOfLand.push_back(fillPieceOfLand());
    }
    outResult(piecesOfLand);
}