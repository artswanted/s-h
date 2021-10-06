#include <iostream>
#include <map>
#include <string>

/*int main()
{
    std::map <int, std::string> registry;
    std::string answer;
    int count = 0;
    
    while (true)
    {
        std::cout << "Please input a name" << std::endl;
        std::cin >> answer;
        if (answer == "next")
        {
            std::cout << registry.begin()->second << std::endl;
            registry.erase(registry.begin());
        }
        else
        {
            //std::cout << answer + std::to_string(count) << std::endl;
            //registry.insert(std::pair<std::string, std::string>(answer + std::to_string(count), answer));
            int counter = std::atoi(answer.c_str());
            counter += count;
            registry.insert(std::make_pair(counter, answer));
            count++;
        }
    }
}*/

int main()
{
    std::map <std::string, int> registry;
    std::string answer;
    int count = 1;

    while (true)
    {
        std::cout << "Please input a name" << std::endl;
        std::cin >> answer;
        if (answer == "next")
        {
            std::cout << registry.begin()->first << std::endl;
            std::map <std::string, int>::iterator it = registry.begin();
            if (it->second > 1) {
                int iTemp = it->second - 1;
                std::string tempName = it->first;
                registry.erase(registry.begin());
                registry.insert(std::make_pair(tempName, iTemp));
            }
            else {
                registry.erase(registry.begin());
            }
        }
        else
        {
            if (registry.size() > 0){
                bool temp = true;
                for (std::map <std::string, int>::iterator it = registry.begin(); it != registry.end(); it++) {
                    if (it->first == answer) {
                        int iTemp = it->second + 1;
                        registry.erase(answer);
                        registry.insert(std::make_pair(answer, iTemp));
                        temp = false;
                        break;
                    }
                }
                if (temp) {
                    registry.insert(std::make_pair(answer, count));
                }
            }
            else {
                registry.insert(std::make_pair(answer, count));
            }

        }
    }
}

