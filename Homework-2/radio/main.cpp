#include <iostream>

float choiceStation(const float *array, int channel){
    return (array[channel-1]);
}

int main() {
    const float station[10] = {
            90.2f, 91.4f, 94.7f, 101.2f, 102.5f,
            103.1f, 104.2f, 104.6f, 105.8f, 107.f
    };
    int channel;

    std::cout << "Hello, Radio!" << std::endl;
    std::cout << "Correct station is " << station[0] << std::endl;
    do {
        std::cout << "Enter station number: ";
        std::cin >> channel;
        if (channel > 0 && channel <= 10){
            std::cout << "New station is " << choiceStation(station, channel) << std::endl;
        }
        else if (channel == 0) break;
        else std::cout << "Incorrect input!" << std::endl;
    } while (true);
    std::cout << "Good bye!";
    return 0;
}
