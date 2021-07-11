#include <iostream>
#include <fstream>

int main() {
    double dTotalSum = 0;
    int iMaxSalary = 0;
    std::string sFullName;

    std::ifstream payList ("../payouts.txt");
    if (payList.is_open()){
        while(!payList.eof()){
            std::string firstName, lastName, date;
            double dSalary = 0;
            payList >> firstName >> lastName >> dSalary >> date;
            std::cout << firstName << " " << lastName << " " << dSalary << " " << date << std::endl;
            dTotalSum += dSalary;
            if (iMaxSalary < dSalary) {
                sFullName = firstName + " " + lastName;
                iMaxSalary = dSalary;
            }
        }
        std::cout << std::endl;
        std::cout << "Found paid out - " << dTotalSum << '\n';
        std::cout << sFullName << " " << iMaxSalary << '\n';
    } else {
        std::cerr << "File is not exist!";
    }
}
