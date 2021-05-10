#include <iostream>
#include <string>

int main() {
    std::string sConvertToDouble;

    std::cout << "Input whole part: ";
    int iTemp;
    std::cin >> iTemp;
    sConvertToDouble = std::to_string (iTemp);
    sConvertToDouble += ".";

    std::cout << "Input fraction part: ";
    std::cin >> iTemp;
    sConvertToDouble += std::to_string (iTemp);

    double number = std::stod (sConvertToDouble);

    std::cout << "Double number is " << number;
    return 0;
}
