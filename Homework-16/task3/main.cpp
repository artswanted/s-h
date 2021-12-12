#include <iostream>

class Display
{
public:
    int x;
    int y;
    int width;
    int height;
};



class Command
{
private:
    Display myDisplay;
public:
    void move ()
    {
        int newX, newY;
        std::cout << "Please enter new beginning:" << std::endl;
        std::cin >> newX >> newY;
        while ((newX + myDisplay.width) > 80 && ((newY + myDisplay.height) > 50))
        {
            std::cout << "Incorrect input, please try again" << std::endl;
            std::cin >> newX >> newY;
        }
        myDisplay.x = newX;
        myDisplay.y = newY;
    };
    void resize ()
    {
        int newWidth, newHeight;
        std::cout << "Please enter new width and new heught of the window" << std::endl;
        std::cin >> newWidth >> newHeight;
        while ((myDisplay.x+newWidth) > 80 && (myDisplay.y + newHeight) > 50)
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
                if (i >= myDisplay.y && i <= (myDisplay.y+myDisplay.height) && j>=myDisplay.x && j<=(myDisplay.x + myDisplay.width)) std::cout << "1";
                else std::cout << "0";
            }
            std::cout << std::endl;
        }
    };
};

int main() {
    Display myDisplay;
    std::cout << "Please enter initial parameters of Window" << std::endl;
    std::cin >> myDisplay.x >> myDisplay.y >> myDisplay.width >> myDisplay.height;
    while ((myDisplay.x+myDisplay.width) > 80 && (myDisplay.y + myDisplay.height) > 50)
    {
        std::cout << "Incorrect entry, please try again" << std::endl;
        std::cin >> myDisplay.x >> myDisplay.y >> myDisplay.width >> myDisplay.height;
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
                std::cout << "! Incorrect command. Try again !";
                break;
        }while (true);
    }
}