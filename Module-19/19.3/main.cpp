#include <iostream>
#include <sstream>


double totalResult (double num1, char action, double num2)
{
    if (action == '+') return num1 + num2;
    else if (action == '*') return num1 * num2;
    else if (action == '-') return num1 - num2;
    else return num1 / num2;
}


int main() {
    std::stringstream sstream;
    std::string sTemp;

    std::cout << "Write number1, action(+, -, *, /), number2:";
    std::cin >> sTemp;
    sstream << sTemp;

    double num1, num2;
    char action;
    sstream >> num1 >> action >> num2;

    if (num2 != 0 && (action == '+' || action == '-' || action == '*' || action == '/'))
    {
        double total = totalResult (num1, action, num2);
        std::cout << num1 << " " << action << " " << num2 << " = " << total << std::endl;
    }
    else if (num2 == 0) std::cerr << "You can't divide by zero";
    else std::cerr << "Error! Unknown action.";

    return 0;
}