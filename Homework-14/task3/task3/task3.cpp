#include <iostream>
#include <ctime>
#include <iomanip>
#include <windows.h>
#pragma comment(lib, "winmm.lib")

int main() {
    std::cout << "Input time: ";
    std::tm time;
    std::cin >> std::get_time(&time, "%M:%S");
    std::time_t t = std::time(nullptr) + time.tm_min * 60 + time.tm_sec;

    std::time_t delta = t - std::time(nullptr);
    int temp_data = delta % 60;

    while (true)
    {
        delta = t - std::time(nullptr);
        if (delta <= 0) break;

        if (temp_data != delta % 60) {
            system("CLS");
            std::cout << delta / 60 << ":" << delta % 60 << std::endl;
            temp_data = delta % 60;
        }
        
        
    }
    system("CLS");
    std::cout << "BEEP! BEEP!\n";
}
