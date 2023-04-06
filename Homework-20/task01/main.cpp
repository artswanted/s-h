#include <iostream>
#include <cpr/cpr.h>

int main() {
    std::string url = "https://httpbin.org/";

    std::string command;
    while (command != "exit") {
        std::cout << "Enter a command (get, post, put, delete, patch): ";
        std::cin >> command;

        if (command == "get") {
            cpr::Response r = cpr::Get(cpr::Url{url + "get"});
            std::cout << r.text << std::endl;
        } else if (command == "post") {
            cpr::Response r = cpr::Post(cpr::Url{url + "post"}, cpr::Payload{{"key", "value"}});
            std::cout << r.text << std::endl;
        } else if (command == "put") {
            cpr::Response r = cpr::Put(cpr::Url{url + "put"}, cpr::Payload{{"key", "value"}});
            std::cout << r.text << std::endl;
        } else if (command == "delete") {
            cpr::Response r = cpr::Delete(cpr::Url{url + "delete"});
            std::cout << r.text << std::endl;
        } else if (command == "patch") {
            cpr::Response r = cpr::Patch(cpr::Url{url + "patch"}, cpr::Payload{{"key", "value"}});
            std::cout << r.text << std::endl;
        }
    }

    return 0;
}
