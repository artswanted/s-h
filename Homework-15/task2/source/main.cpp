#include <main.h>

int main() {
        int answer=0;
    while (answer != 6)
    {
        std::string operateMemory = loadMemCache();
        std::cout << "Please choose needed action" << std::endl;
        std::cout << "1. SUM" << std::endl;
        std::cout << "2. SAVE" << std::endl;
        std::cout << "3. LOAD" << std::endl;
        std::cout << "4. INPUT" << std::endl;
        std::cout << "5. DISPLAY" << std::endl;
        std::cout << "6. EXIT" << std::endl;
        std::cin >> answer;
        if (answer == 1) compute (operateMemory);
        else if (answer == 2) write (operateMemory);
        else if (answer == 3) read (operateMemory);
        else if (answer == 4) input (operateMemory);
        else if (answer == 5) display(operateMemory);
        writeMemoryCache(operateMemory);
    }
    std::cout << "Simulation is finished" << std::endl;

}