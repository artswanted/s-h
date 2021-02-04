#include <iostream>

bool iChecker (std::string ip){
    bool result = true;
    std::string temp;
    int number = 0;
    int dot = 0;
    for (int i = 0; i < ip.size(); i++){
        if (ip[i] < '0' || ip[i] > '9') {
            if (ip[i] != '.') {
                result = false;
                break;
            }
        }

        if (ip[i] != '.' && temp.size() < 3) {
            temp += ip[i];
        } else if (ip[i] == '.' && temp.size() > 0){
            if (temp.size() == 3){
                number = ((temp[0] - '0') * 100) + ((temp[1] - '0') * 10) + (temp[2] - '0');
            }
            else if (temp.size() == 2) {
                number = ((temp[0] - '0') * 10) + (temp[1] - '0');
            }
            else number = temp[0] - '0';
            std::cout << number;
            if (number > 255 || number < 0) {
                //std::cout << "break?? " << number << std::endl;
                result = false;
                break;
            }
            temp.clear();
            number = 0;
            dot++;
        } else {
            result = false;
            break;
        }
        //std::cout << temp << std::endl;

    }
    if (dot != 3) result = false;
    return result;
}

int main() {
    std::string ip;
    std::cout << "Write IP: " << std::endl;
    std::cin >> ip;
    std::cout << (iChecker(ip) ? "Yes" : "No");

    return 0;
}
