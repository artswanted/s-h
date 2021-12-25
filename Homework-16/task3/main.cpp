#include <iostream>

class Window
{
private:
    int x;
    int y;
    int width;
    int height;
public:
    int setX(int newX){
        x = newX;
    };
    int getX(){
        return x;
    };
    int setY(int newY){
        y = newY;
    };
    int getY(){
        return y;
    };
    int setWidth(int w){
        width = w;
    };
    int getWidth(){
        return width;
    };
    int setHeight(int h){
        height = h;
    };
    int getHeight(){
        return height;
    };
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
        while ((newX + myWindow.getWidth()) > myMonitor.sizeX() && ((newY + myWindow.getHeight()) > myMonitor.sizeY()))
        {
            std::cout << "Incorrect input, please try again" << std::endl;
            std::cin >> newX >> newY;
        }
        myWindow.setX(newX);
        myWindow.setY(newY);
    };
    void resize ()
    {
        int newWidth, newHeight;
        std::cout << "Please enter new width and new heught of the window" << std::endl;
        std::cin >> newWidth >> newHeight;
        while ((myWindow.getX()+newWidth) > myMonitor.sizeY() && (myWindow.getY() + newHeight) > myMonitor.sizeY())
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
                if (i >= myWindow.getY() && i <= (myWindow.getY()+myWindow.getHeight()) && j>=myWindow.getX() && j<=(myWindow.getX() + myWindow.getWidth())) std::cout << "1";
                else std::cout << "0";
            }
            std::cout << std::endl;
        }
    };
};

int main() {
    Window myWindow;
    Monitor myMonitor;
    int x,y,w,h;
    std::cout << "Please enter initial parameters of Window" << std::endl;
    std::cin >> x >> y >> w >> h;
    myWindow.setX(x);
    myWindow.setY(y);
    myWindow.setWidth(w);
    myWindow.setHeight(h);
    while ((myWindow.getX()+myWindow.getWidth()) > myMonitor.sizeX() && (myWindow.getY() + myWindow.getHeight()) > myMonitor.sizeY())
    {
        std::cout << "Incorrect entry, please try again" << std::endl;
        std::cin >> x >> y >> w >> h;
        myWindow.setX(x);
        myWindow.setY(y);
        myWindow.setWidth(w);
        myWindow.setHeight(h);
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