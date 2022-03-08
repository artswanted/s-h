#include <iostream>
#include <cmath>
#include <thread>
#include <chrono>
#include <mutex>
#include <vector>
#include <ctime>
#include <string>

std::vector <bool> railwayStation = {false, false, false};
std::mutex railwayStation_access;

class Train
{
    std::string m_name = "unknown";
    int m_time = 0;
    bool m_arrived = false;
public:
    Train (std::string in_name, int in_time)
    {
        m_time = in_time;
        m_name = in_name;
    }
    int getTime (int x)
    {
        return m_time = x;
    }

    int arriving()
    {
        return m_time -= 1;
    }

    bool getArrival()
    {
        return m_arrived;
    }

    bool setArrival()
    {
        if (m_time == 0) return m_arrived=true;
        else return m_arrived = false;
    }

    std::string setName(std::string foo)
    {
        return foo = m_name;
    }

    std::string getName()
    {
        return m_name;
    }
};

void comeToReailwayStation(Train myTrain)
{
    myTrain.setArrival();
    while (!myTrain.getArrival())
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        myTrain.arriving();
        myTrain.setArrival();
    }
    railwayStation_access.lock();
    std::cout << "Train " << myTrain.getName() << " is arrived " << std::endl;
    std::cout << "Waiting for depart. PLease enter a command depart" << std::endl;
    std::string buffer;
    std::cin >> buffer;
    while (buffer != "depart")
    {
        std::cout << " Incorrect input command, please try again " << std::endl;
        std::cin >> buffer;
    }
    for (int i = 0; i < railwayStation.size(); i++)
    {
        if (railwayStation[i] == false)
        {
            railwayStation[i] = true;
            break;
        }
    }
    railwayStation_access.unlock();
}

bool allDepart ()
{
    for (int i = 0; i < railwayStation.size(); i++)
    {
        if (railwayStation[i] == false) return false;
    }
    return true;
}



int main() {
    std::vector <std::string> name;
    std::string temp;
    int time [3];
    for(int i = 0; i < 3; i++)
    {
        std::cout << "Please enter name and travel time for " << i + 1 << "train" << std::endl;
        std::cin >> temp >> time[i];
        name.push_back(temp);
    }
    class Train A (name[0], time[0]);
    class Train B (name[1], time[1]);
    class Train C (name[2], time[2]);
    std::thread run1 (comeToReailwayStation, A);
    std::thread run2 (comeToReailwayStation, B);
    std::thread run3 (comeToReailwayStation, C);
    run1.join();
    run2.join();
    run3.join();
}