#include <iostream>

class Monitor
{
public:
    int x;
    int y;
    int width;
    int height;
};

Monitor myMonitor;

class Command
{
public:
    void move ()
    {
        int newX, newY;
        std::cout << "Please enter new beginning:" << std::endl;
        std::cin >> newX >> newY;
        while ((newX + myMonitor.width) > 80 && ((newY + myMonitor.height) > 50))
        {
            std::cout << "Incorrect input, please try again" << std::endl;
            std::cin >> newX >> newY;
        }
        myMonitor.x = newX;
        myMonitor.y = newY;
    };
    void resize ()
    {
        int newWidth, newHeight;
        std::cout << "Please enter new width and new heught of the window" << std::endl;
        std::cin >> newWidth >> newHeight;
        while ((myMonitor.x+newWidth) > 80 && (myMonitor.y + newHeight) > 50)
        {
            std::cout << "Incorrect input, please try again" << std::endl;
            std::cin >> newWidth >> newHeight;
        }
    };
    void display ()
    {
        for (int i = 0; i <= 50; i++)
        {
            for (int j = 0; j <=80; j++)
            {
                if (i >= myMonitor.y && i <= (myMonitor.y+myMonitor.height) && j>=myMonitor.x && j<=(myMonitor.x + myMonitor.width)) std::cout << "1";
                else std::cout << "0";
            }
            std::cout << std::endl;
        }
    };
};

int main() {
    std::cout << "Please enter initial parameters of Window" << std::endl;
    std::cin >> myMonitor.x >> myMonitor.y >> myMonitor.width >> myMonitor.height;
    while ((myMonitor.x+myMonitor.width) > 80 && (myMonitor.y + myMonitor.height) > 50)
    {
        std::cout << "Incorrect entry, please try again" << std::endl;
        std::cin >> myMonitor.x >> myMonitor.y >> myMonitor.width >> myMonitor.height;
    }
    int answer;
    Command myCommand;
    while (answer != 3)
    {
        std::cout << "Please choose a command" << std:: endl;
        std::cout << "0. move Window" << std::endl;
        std::cout << "1. resize Window" << std::endl;
        std::cout << "2.display Window" << std::endl;
        std::cout << "3.exit" << std::endl;
        std::cin >> answer;
        switch (answer)
        {
            case 0:
                myCommand.move();
                break;
            case 1:
                myCommand.resize();
                break;
            case 2:
                myCommand.display();
                break;
            case 3:
                break;
            default:
                std::cout << "! Incorrect command. Try again !";
                break;
        }
    }
}