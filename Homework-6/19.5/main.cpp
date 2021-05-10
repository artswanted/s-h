#include <iostream>
#include <sstream>


int automatics = 0;


enum Automatic
{
    TOTAL_POWER = 1,
    SOCKET_POWER = 2,
    LIGHT_IN_HOUSE = 4,
    LIGHT_ON_GARDEN = 8,
    HOUSE_HEATING = 16,
    WATER_HEATING = 32,
    CONDITIONER = 64
};


bool convertMovement (std::string movement)
{
    return movement == "yes";
}


bool convertLight (std::string light)
{
    return light == "on";
}


void checkLightInHouse (bool lightOn)
{
    if ((lightOn) && ((automatics & LIGHT_IN_HOUSE) != LIGHT_IN_HOUSE))
    {
        automatics |= LIGHT_IN_HOUSE;
        std::cout << "\tLight in house is ON";
    }
    else
    if ((automatics & LIGHT_IN_HOUSE) == LIGHT_IN_HOUSE)
    {
        automatics &= ~LIGHT_IN_HOUSE;
        std::cout << "\tLight in house is OFF" << std::endl;
    }
}


void checkTemperatureLight (int time)
{
    int startTime = 16;
    int endTime = 20;
    int hightTemperature = 5000;
    int lowTemperature = 2700;

    std::cout << "\tIn house light temperature is ";
    if (time < startTime)
        std::cout << hightTemperature << 'K' << std::endl;
    else
    if (time < endTime)
        std::cout << hightTemperature - ((hightTemperature - lowTemperature) /
                                         (endTime - startTime) * (time - startTime)) << 'K' << std::endl;
    else
        std::cout << lowTemperature << 'K' << std::endl;
}


void checkTemperatureOut (int temperature)
{
    if ((temperature < 0) & ((automatics & WATER_HEATING) != WATER_HEATING))
    {
        automatics |= WATER_HEATING;
        std::cout << "\tWater heating is ON" << std::endl;
    }
    else
    if ((temperature > 5) & ((automatics & WATER_HEATING) == WATER_HEATING))
    {
        automatics &= ~WATER_HEATING;
        std::cout << "\tWater heating is OFF" << std::endl;
    }
}


void checkTemperatureIn (int temperature)
{
    if ((temperature < 22) & ((automatics & HOUSE_HEATING) != HOUSE_HEATING))
    {
        automatics |= HOUSE_HEATING;
        std::cout << "\tHouse heating is ON" << std::endl;
    }
    else
    if ((temperature >= 25) & ((automatics & HOUSE_HEATING) == HOUSE_HEATING))
    {
        automatics &= ~HOUSE_HEATING;
        std::cout << "\tHouse heating is OFF" << std::endl;
    }
}


void checkConditioner (int temperature)
{
    if ((temperature >= 30) & ((automatics & CONDITIONER) != CONDITIONER))
    {
        automatics |= CONDITIONER;
        std::cout << "\tConditioner is ON" << std::endl;
    }
    else
    if ((temperature <= 25) & ((automatics & CONDITIONER) == CONDITIONER))
    {
        automatics &= ~CONDITIONER;
        std::cout << "\tConditioner is OFF" << std::endl;
    }
}


void checkLightOnGarden (int time, bool movement)
{
    if (((time < 5 || time > 16) && movement) &
        ((automatics & LIGHT_ON_GARDEN) != LIGHT_ON_GARDEN))
    {
        automatics |= LIGHT_ON_GARDEN;
        std::cout << "\tLight on garden is ON" << std::endl;
    }
    else
    if (((time >= 5 && time <= 16) || !movement) &
        ((automatics & LIGHT_ON_GARDEN) == LIGHT_ON_GARDEN))
    {
        automatics &= ~LIGHT_ON_GARDEN;
        std::cout << "\tLight on garden is OFF" << std::endl;
    }
}


void time (int i)
{
    std::cout << "\n\t~~~ Current time is ";
    if (i < 10)
        std::cout << "0" << i;
    else
        std::cout << i;
    std::cout << ":00 ~~~" << std::endl;
}



int main() {
    const int totalTime = 48;

    int tempIn, tempOut;
    bool movement, lightOn;

    for (int i = 0; i < totalTime; ++i)
    {
        time (i);

        std::cout << "Input temperature outside house, inside house, " << std::endl;
        std::cout << "have outside movement (yes/no), light in house (on/off): ";
        std::string temp;
        getline(std::cin, temp);

        std::stringstream sstream;
        sstream << temp;

        std::string movementStr, lightOnStr;
        sstream >> tempOut >> tempIn >> movementStr >> lightOnStr;

        lightOn = convertLight(lightOnStr);
        movement = convertMovement(movementStr);

        checkTemperatureOut (tempOut);
        checkTemperatureIn (tempIn);
        checkLightOnGarden (i % 24, movement);
        checkConditioner(tempIn);
        checkLightInHouse (lightOn);
        if (lightOn)
            checkTemperatureLight (i % 24);
    }
}