#include <iostream>
#include <string>
#include <map>
#include <cpr/cpr.h>

int main() {
    std::string key, value;
    std::string method;
    std::map<std::string, std::string> args;

    // ввод аргументов
    while (key != "post" && key != "get") {
        std::cout << "Введите название аргумента: ";
        std::getline(std::cin, key);

        if (key != "post" && key != "get") {
            std::cout << "Введите значение аргумента: ";
            std::getline(std::cin, value);
            args[key] = value;
        }
    }

    if (key == "post") {
        method = "POST";
    } else if (key == "get") {
        method = "GET";
    }

    // создание запроса
    cpr::Response response;
    if (method == "POST") {
        cpr::Payload payload;
        for (const auto& arg : args) {
            payload.AddParameter({arg.first, arg.second});
        }
        response = cpr::Post(cpr::Url{"https://httpbin.org/post"}, payload);
    } else if (method == "GET") {
        std::string url = "https://httpbin.org/get";
        for (const auto& arg : args) {
            url += "?" + arg.first + "=" + arg.second;
        }
        response = cpr::Get(cpr::Url{url});
    }

    // вывод ответа
    if (response.status_code == 200) {
        std::cout << "Response content: " << response.text << std::endl;
        if (method == "POST") {
            std::cout << "POST arguments: " << std::endl;
            for (const auto& arg : args) {
                std::cout << arg.first << " : " << arg.second << std::endl;
            }
        } else if (method == "GET") {
            std::cout << "GET arguments: " << std::endl;
            for (const auto& arg : args) {
                std::cout << arg.first << " : " << arg.second << std::endl;
            }
        }
    } else {
        std::cerr << "Error: " << response.status_code << std::endl;
    }

    return 0;
}
