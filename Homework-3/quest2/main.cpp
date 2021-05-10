#include <iostream>
#include <vector>

int main() {
    std::vector<float> vecPrices{2.5, 4.25, 3.0, 10.0};
    std::vector<std::string> vecList{"1. Bread: 2.5RUB", "2. Milk: 4.25RUB", "3. Water: 3.0", "4. Juice: 10.0RUB"};
    std::vector<int> vecSum;
    std::vector<std::string> boughtList;
    int n = 0;
    float result = 0.f;

    for (int list = 0; list < vecList.size(); list++){
        std::cout << vecList[list] << std::endl;
    }

    std::cout << "Enter your choice:" << std::endl;

    while (n != -1){
        std::cin >> n;
        if (n <= vecPrices.size()) vecSum.push_back(n);
        else if (n == -1) std::cout << "Thanks you!" << std::endl;
        else std::cout << "Error. Try again." << std::endl;
    }

    for (int i = 0; i < vecSum.size(); i++){
        std::cout << vecPrices[vecSum[i]-1];
        result += vecPrices[vecSum[i]-1];
        boughtList.push_back(vecList[vecSum[i]-1]);
    }

    std::cout << "Your total price for items are " << result << "RUB" << std::endl << "Your items list:" << std::endl;
    for (int i = 0; i < boughtList.size(); i++){
        std::cout << boughtList[i] << std::endl;
    }
    return 0;
}
