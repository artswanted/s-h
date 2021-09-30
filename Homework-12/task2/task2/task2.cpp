#include <iostream>
#include <map>
#include <string>

int main()
{
    std::map <std::string, std::string> registry;
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
            registry.insert(std::make_pair(answer + std::to_string(count), answer));
            count++;
        }
    }
}


