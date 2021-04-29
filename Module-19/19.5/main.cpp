#include <iostream>

int iStatus = 0;

enum eFlap {
    POWER_HOUSE = 1,
    SOCKET = 2,
    LIGHT_INSIDE = 4,
    LIGHT_GARDEN = 8,
    HOUSE_HEATING = 16,
    WATER_HEATING = 32,
    CONDITIONER = 64,
    SENSOR_MOVE = 128
};

enum eSensord{
    OUTSIDE_TEMPERATURE,
    INSIDE_TEMPERATURE,
    MOVEMENT_SENSOR
};

void inputParametr(int iTypeSensor){
    int iValue;
    do {
        std::cin >> iValue;
        if (iTypeSensor == OUTSIDE_TEMPERATURE){
            if (iValue >= -50 && iValue <= 50)
            {
                if (iValue <= 0 && iStatus ^ WATER_HEATING){
                    iStatus |= WATER_HEATING;
                    std::cout << "Water heating is enabled!" << std::endl;
                }
                if (iValue >= 5 && iStatus & WATER_HEATING){
                    iStatus &= ~(WATER_HEATING);
                    std::cout << "Water heating is disabled!" << std::endl;
                }
                break;
            }
            else std::cout << "Error! Try again from -50 to +50:";
        } else if (iTypeSensor == INSIDE_TEMPERATURE){
            if (iValue >= -50 && iValue <= 50)
            {
                if (iValue <= 22 && iStatus ^ HOUSE_HEATING){
                    iStatus |= HOUSE_HEATING;
                    std::cout << "House heating is enabled!" << std::endl;
                }
                if (iValue >= 25 && iStatus & HOUSE_HEATING){
                    iStatus &= ~(HOUSE_HEATING);
                    std::cout << "House heating is disabled!" << std::endl;
                }
                if (iValue >= 30 && iStatus ^ CONDITIONER){
                    iStatus |= CONDITIONER;
                    std::cout << "House's conditioner is enabled!" << std::endl;
                }
                if (iValue <= 25 && iStatus & CONDITIONER){
                    iStatus &= ~(CONDITIONER);
                    std::cout << "House's conditioner is disabled!" << std::endl;
                }
                break;
            }
            else std::cout << "Error! Try again from -50 to +50:";
        } else if (iTypeSensor == MOVEMENT_SENSOR){
            if (iValue == 1 && iStatus & SENSOR_MOVE) {
                iStatus |= SENSOR_MOVE;
                break;
            }else if (iValue == 2 && iStatus ^ SENSOR_MOVE){
                iStatus &= ~(SENSOR_MOVE);
                break;
            } else {
                std::cout << "Error! Try again:";
            }
        } else {
            std::cerr << "Sensor type is wrong!" << std::endl;
            iValue = 0;
            break;
        }
    } while (true);

    //return iValue;
}

int main() {
    int tSensorOutside = 0;
    int tSensorInside = 0;
    bool bMovementSensor = false;
    int iTime = 0;
    do{
        std::cout << "Input paramerts!" << std::endl;
        std::cout << "Temperature Outside:";
        inputParametr(OUTSIDE_TEMPERATURE);
        std::cout << "Temperature Inside:";
        inputParametr(INSIDE_TEMPERATURE);
        std::cout << "Move sensor:" << std::endl << "1. Detected;" << std::endl << "2. Undetected;" << std::endl;
        inputParametr(MOVEMENT_SENSOR);
        //garden light
        if (iTime >= 16 && iTime <= 5){
            if (iStatus & SENSOR_MOVE){
                iStatus |= LIGHT_GARDEN;
            } else {iStatus &= ~(LIGHT_GARDEN);};
        } else if (iStatus & SENSOR_MOVE) {iStatus &= ~(LIGHT_GARDEN);};

        //time counter
        if (iTime == 23){
            iTime = 0;
        } else {
            iTime++;
        }
    } while (true);
    return 0;
}
