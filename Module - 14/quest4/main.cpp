#include <iostream>

bool iChecker (std::string ip){
    bool result = true;
    std::string temp;
    int number;
    for (int i = 0; i < ip.size(); i++){
        if (ip[i] != '.' && temp.size() < 3) {
            temp += ip[i];
        } else if (ip[i] == '.' && temp.size() > 0){
            //
            if (temp.size() == 3) number = (temp[0] * 100) + (temp[1] * 10) + temp[2];
            else if (temp.size() == 2) number = (temp[0] * 10) + temp[1];
            else number = temp[1];
            //
            if (number > 255 || number < 0) {
                result = false;
                break;
            }
        } else {
            result = false;
            break;
        }


    }

    return result;
}

int main() {
    std::string ip;

    std::cout << "Write IP: " << std::endl;
    std::cin >> ip;
    std::cout << (iChecker(ip) ? "Yes" : "No");

    return 0;
}
