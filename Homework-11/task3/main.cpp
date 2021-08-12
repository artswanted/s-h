#include <iostream>
#include <cmath>
#include <ctime>

struct coordinate
        {
    float x = rand() % 60 - 30;
    float y = rand() % 60 - 30;
        };

void initialization (coordinate& a, coordinate& b)
{
    std::cout << "First vector has foolowing coordinates " << a.x << " " << a.y << std::endl;
    std::cout << "Second vector has foolowing coordinates " << b.x << " " << b.y << std::endl;
}

coordinate sum (coordinate& a, coordinate& b)
{
    coordinate v;
    v.x = a.x + b.x;
    v.y = a.y + b.y;
    return v;
}

coordinate minus(coordinate& a, coordinate& b)
{
    coordinate v;
    v.x = a.x - b.x;
    v.y = a.y - b.y;
    return v;
}

coordinate scale(coordinate& a, int count)
{
    coordinate v;
    v.x = a.x * count;
    v.y = a.y * count;
    return v;
}

int length (coordinate& a)
{
    int temp = sqrt( pow(a.x, 2) + pow(a.y, 2) );
    return temp;
}

coordinate normalize (coordinate& a)
{
    coordinate v;
    v.x = (a.x) / sqrt( pow(a.x, 2) + pow(a.y, 2) );
    v.y = (a.y) / sqrt( pow(a.x, 2) + pow(a.y, 2) );
    return v;
}

int main() {
    std::srand(std::time(0));
    int buffer = 0;
    coordinate New;
    coordinate foo[2];
    initialization (foo[0], foo[1]);
    std::string answer;
    std::cout << "What you want to do?" << std::endl;
    std::cin >> answer;
    if (answer == "Summary")
    {
        New = sum(foo[0], foo[1]);
        std::cout << "New vector has following parameters:" << std::endl;
        std::cout << "X: " << New.x << std::endl;
        std::cout << "Y: " << New.y << std::endl;
    }
    else if (answer == "Minus")
    {
        New = minus(foo[0], foo[1]);
        std::cout << "New vector has following parameters:" <<std::endl;
        std::cout << "X: " << New.x << std::endl;
        std::cout << "Y: " << New.y << std::endl;
    }
    else if (answer == "Length")
    {
        buffer = length (foo[0]);
        std::cout << "Length of 1 vector is " << buffer << std::endl;
        buffer = length (foo[1]);
        std::cout << "Length of 2 vector is " << buffer << std::endl;
    }
    else if (answer == "Normalize")
    {
        New = normalize (foo[0]);
        std::cout << "First normalize vector is " << std::endl;
        std::cout << "X: " << New.x << std::endl;
        std::cout << "Y: " << New.y << std::endl;
        New = normalize (foo[1]);
        std::cout << "Second normalize vector is " << std::endl;
        std::cout << "X: " << New.x << std::endl;
        std::cout << "Y: " << New.y << std::endl;
    }
    else if (answer == "Scale")
    {
        int count;
        std::cout << "How much?" << std::endl;
        std::cin >> count;
        New = scale(foo[0], count);
        std::cout << "First new vector has following parameters:" << std::endl;
        std::cout << "X: " << New.x << std::endl;
        std::cout << "Y: " << New.y << std::endl;
        New = scale(foo[1], count);
        std::cout << "Second new vector has following parameters:" << std::endl;
        std::cout << "X: " << New.x << std::endl;
        std::cout << "Y: " << New.y << std::endl;
    }
    else std::cout << "Wrong command" << std::endl;
}