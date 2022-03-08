#include <iostream>
#include <cmath>
#include <thread>
#include <chrono>
#include <mutex>
#include <vector>
#include <ctime>
#include <string>

std::vector <std::string> menu = {"pizza", "steak", "sushi", "salat"};
std::vector <std::thread> orders;
std::vector <std::string> available;
std::mutex kitchen_available;
std::mutex order_available;

void createOrder()
{
    order_available.lock();
    std::this_thread::sleep_for(std::chrono::seconds(std::rand() % 5 + 5));
    std::string order = menu[std::rand() % 3];
    std::cout << "Your want order " << order << std::endl;
    order_available.unlock();
    kitchen_available.lock();
    std::this_thread::sleep_for(std::chrono::seconds(std::rand() % 10 + 5));
    std::cout << order << " is ready!" << std::endl;
    available.push_back(order);
    kitchen_available.unlock();
}

int main() {
    std::srand(std::time(0));
    for (int i = 0; i < 10; i++) {
        orders.emplace_back(createOrder);
        orders[i].detach();
    }
    int k = 0;
    while (k < 9) {
        std::this_thread::sleep_for(std::chrono::seconds(30));
        std::cout << "Courier is come \n" << "He will pick-up:" << std::endl;
        for (int i = 0; i < available.size(); i++) {
            std::cout << available[i] << std::endl;
        }
        k += available.size();
        available.clear();
    }
}