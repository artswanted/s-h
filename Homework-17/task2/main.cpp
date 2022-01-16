#include <iostream>

class Core
{
public:
    float x, y;
    std::string color = "unknown";

    void colorChoose()
    {
        std::cout << "Please choose color of shape:" << std::endl;
        std::cout << "1. red" << std::endl;
        std::cout << "2. blue" << std::endl;
        std::cout << "3. green" << std::endl;
        int choose = 0;
        std::cin >> choose;
        switch (choose)
        {
            case (1):
                color = "red";
                break;
            case (2):
                color = "blue";
                break;
            case (3):
                color = "green";
                break;
        }
    }
};

class Square : public Core
{
public:
    float distanceToEdge = 0;
    Square (float m) : distanceToEdge(m)
    {

    }
    void squareSize()
    {
        colorChoose();
        std::cout << "Square size is " << (2 * distanceToEdge) * (2 * distanceToEdge) << std::endl;
    }
    void squareOutside ()
    {
        std::cout << "It's equal" << std::endl;
    }
};

class Circle : public Core
{
public:
    float radius = 0;
    Circle (float m) : radius(m)
    {

    }
    void circleSize()
    {
        colorChoose();
        std::cout << "Circle size is " << 3.14f * radius * radius << std::endl;
    }
    void squareOutside()
    {
        std::cout << "Square outside has follwoing size of edge: " << 2 * radius << std::endl;
    }
};

class Triangle : public Core
{
public:
    float distanceToApex;
    Triangle (float m) : distanceToApex (m)
    {

    }
    void triangleSize()
    {
        colorChoose();
        // 0.86 cos30, 0.433 square koef
        std::cout << "Triangle square is " << 0.433f * (2 * 0.86f * distanceToApex) * (2 * 0.86f * distanceToApex) << std::endl;
    }
    void squareOutside()
    {
        std::cout << "Square outside has follwoing size of edge: " << 0.86f * 2 * 0.86f * distanceToApex << std::endl;
    }
};

class Rectangle : public Core
{
    float shortDistance, longDistance;
public:
    Rectangle (float m, float n) : shortDistance(m), longDistance (n)
    {

    }
    void rectangleSize()
    {
        colorChoose();
        std::cout << "rectangle square is " << 4 * shortDistance * longDistance << std::endl;
    }
    void squareOutside()
    {
        std::cout << "Square outside has follwoing size of edge: " << longDistance << std::endl;
    }
};

void squareCreation()
{
    float m;
    std::cout << "Please enter distance to edge: " << std::endl;
    std::cin >> m;
    Square mySquare(m);
    mySquare.squareSize();
    mySquare.squareOutside();
}

void circleCreation()
{
    float m;
    std::cout << "Please enter a radius: " << std::endl;
    std::cin >> m;
    Circle myCircle(m);
    myCircle.circleSize();
    myCircle.squareOutside();
}

void triangleCreation()
{
    float m;
    std::cout << "Please enter a distanse from center to Apex: " << std::endl;
    std::cin >> m;
    Triangle myTriangle(m);
    myTriangle.triangleSize();
    myTriangle.squareOutside();
}

void rectangleCreation()
{
    float m, n;
    std::cout << "Please enter a short and long edges" << std::endl;
    std::cin >> m >> n;
    Rectangle myRectangle(m, n);
    myRectangle.rectangleSize();
    myRectangle.squareOutside();
}

int main()
{
    float answerOne, answerTwo;
    int buffer = 0;
    while (buffer != 5)
    {
        std::cout << "Please choose what shape we will create" << std::endl;
        std::cout << "1. circle" << std::endl;
        std::cout << "2. square" << std::endl;
        std::cout << "3. triangle" << std::endl;
        std::cout << "4. rectangle" << std::endl;
        std::cout << "5. exit" << std::endl;
        std::cin >> buffer;
        switch (buffer)
        {
            case (1):
                circleCreation();
                break;
            case (2):
                squareCreation();
                break;
            case (3):
                triangleCreation();
                break;
            case (4):
                rectangleCreation();
                break;
            case (5):
                break;
            default:
                std::cout << "Incorrect command! Try again:" << std::endl;
                break;
        }
    }

}