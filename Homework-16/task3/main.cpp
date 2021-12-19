#include <iostream>

class Window
{
public:
    int x;
    int y;
    int width;
    int height;
};

class Monitor
{
private:
    int monitorSizeX = 80;
    int monitorSizeY = 50;
public:
    int sizeX(){
        return monitorSizeX;
    }

    int sizeY(){
        return monitorSizeY;
    }
};

class Command
{
private:
    Window myWindow;
    Monitor myMonitor;
public:
    void move ()
    {
        int newX, newY;
        std::cout << "Please enter new beginning:" << std::endl;
        std::cin >> newX >> newY;
        while ((newX + myWindow.width) > myMonitor.sizeX() && ((newY + myWindow.height) > myMonitor.sizeY()))
        {
            std::cout << "Incorrect input, please try again" << std::endl;
            std::cin >> newX >> newY;
        }
        myWindow.x = newX;
        myWindow.y = newY;
    };
    void resize ()
    {
        int newWidth, newHeight;
        std::cout << "Please enter new width and new heught of the window" << std::endl;
        std::cin >> newWidth >> newHeight;
        while ((myWindow.x+newWidth) > myMonitor.sizeY() && (myWindow.y + newHeight) > myMonitor.sizeY())
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
                if (i >= myWindow.y && i <= (myWindow.y+myWindow.height) && j>=myWindow.x && j<=(myWindow.x + myWindow.width)) std::cout << "1";
                else std::cout << "0";
            }
            std::cout << std::endl;
        }
    };
};

int main() {
    Window myWindow;
    Monitor myMonitor;
    std::cout << "Please enter initial parameters of Window" << std::endl;
    std::cin >> myWindow.x >> myWindow.y >> myWindow.width >> myWindow.height;
    while ((myWindow.x+myWindow.width) > myMonitor.sizeX() && (myWindow.y + myWindow.height) > myMonitor.sizeY())
    {
        std::cout << "Incorrect entry, please try again" << std::endl;
        std::cin >> myWindow.x >> myWindow.y >> myWindow.width >> myWindow.height;
    }
    int answer;
    Command myCommand;
    do
    {
        std::cout << "Please choose a command" << std:: endl;
        std::cout << "0. move Window" << std::endl;
        std::cout << "1. resize Window" << std::endl;
        std::cout << "2. display Window" << std::endl;
        std::cout << "3. exit" << std::endl;
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
                std::cout << "! Incorrect command. Try again !\n";
        }
    }while (true);

}