#include <iostream>
#include <ctime>
#include <iomanip>
#include <windows.h>
#pragma comment(lib, "winmm.lib")

int main() {
    std::tm time;
    time.tm_min = 9999;
    std::time_t t = std::time(nullptr) + time.tm_min * 60 + time.tm_sec;

    std::time_t delta = t - std::time(nullptr);
    int temp_data = delta % 120;

    while (true)
    {
        delta = t - std::time(nullptr);
        if (delta <= 0) break;

        if (temp_data != delta % 120) {
            system("CLS");
            std::cout << delta / 120 << ":" << delta % 120 << std::endl;
            temp_data = delta % 120;
        }
        
        
    }
    system("CLS");
    std::cout << "BEEP! BEEP!\n";
}
