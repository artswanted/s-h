#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <vector>

std::vector<std::string> results;
std::mutex results_mtx;

void swim(const std::string& name, double speed)
{
    results_mtx.lock();
    std::cout << name << " started to swim...";
    results_mtx.unlock();
    double distance = 0;
    while (distance <= 100)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        results_mtx.lock();
        std::cout << name << " swam: " << distance << std::endl;
        results_mtx.unlock();
        distance += speed;
    }
    results_mtx.lock();
    std::cout << name << " finished." << std::endl;
    results.push_back(name);
    results_mtx.unlock();
}

int main()
{
    int const n = 6;
    std::vector<std::thread> swimmers;
    std::vector<std::string> names(n);
    std::vector<double> speeds(n);

    for (int i = 0; i < n; ++i) {
        std::cout << "Name #" << i << ":";
        std::cin>>names[i];
    }

    for (int i = 0; i < n; ++i) {
        std::cout << "Speed #" << i << ":";
        std::cin>>speeds[i];
    }

    for (int i = 0; i < n; ++i) {
        swimmers.emplace_back(swim, names[i], speeds[i]);
    }
    for (int i = 0; i < n; ++i) {
        swimmers[i].join();
    }

    for (int i = 0; i < n; ++i) {
        std::cout << i << ". " << results[i] << std::endl;
    }
}