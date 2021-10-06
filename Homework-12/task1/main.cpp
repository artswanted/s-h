#include <iostream>
#include <map>
#include <string>

void include (std::map <std::string, std::string>& nMap, std::map <std::string, std::string>& oMap,std::string foo)
{
    int pos;
    std::string firstPart, secondPart;
    for (pos = 0; foo[pos] != ' '; ++pos);
    for (int a = 0; a < pos; ++a) firstPart += foo[a];
    for (int a = pos + 1; a < foo.length(); ++a) secondPart += foo[a];
    nMap.insert(std::make_pair (firstPart, secondPart));
    oMap.insert(std::make_pair(secondPart, firstPart));
    if (firstPart != oMap[secondPart])
    {
        firstPart += " " + oMap [secondPart];
        std::map <std::string, std::string> :: iterator it;
        for (it = oMap.begin(); it->first != secondPart; ++ it);
        oMap.erase(it);
        oMap.insert(std::make_pair(secondPart, firstPart));
    }
}

int main() {
    std::map <std::string, std::string> nameToPhone;
    std::map <std::string, std::string> phoneToName;
    std::string answer;
    while (true)
    {
        std::cout << "Please enter a request" << std::endl;
        std::getline(std::cin, answer);
        if ((answer[0] >= '0' && answer[0] <= '9') &&
            (answer[answer.length()-1] >= 'a' &&
             answer[answer.length()-1] <= 'z'))
        {
            include (phoneToName, nameToPhone, answer);
        }
        else if (answer[0] >= '0' && answer[0] <= '9')
            std::cout << phoneToName [answer] << std::endl;
        else if (answer[answer.length()-1] >= 'a' &&
                 answer[answer.length()-1] <= 'z')
            std::cout<< nameToPhone [answer]<<std::endl;
        else std::cout << "Error input! Please try again" << std::endl;
    }
}