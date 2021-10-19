#include <iostream>
#include <iomanip>
#include <vector>
#include <ctime>

using namespace std;

struct Person_l
{
    string name = "name";
    int year = 0;
    int month = 0;
    int day = 0;
};

std::vector <Person_l> person;

int main() {

    time_t t = time(nullptr);
    tm local = *localtime(&t);
    int currentMonth = local.tm_mon;
    int currentDate = local.tm_mday;
    int nearestMonth, nearestDate;
    string nearestName;
    int deltaMonth = 11;
    int deltaDay = 30;
    string answer;
    while (true)
    {
        cout << "Please enter a name: " << endl;
        cin >> answer;
        if (answer == "end") break;
        cout << "Please enter burthday in formay YEAR-MONTH-DAY" << endl;
        cin >> get_time(&local, "%Y-%m-%d");
        person.push_back({ answer, local.tm_year, local.tm_mon, local.tm_mday });
    }
    for (int i = 0; i < person.size(); i++)
    {
        int bufferMonth = person[i].month;
        int bufferDate = person[i].day;
        if ((bufferMonth >= currentMonth) && (bufferDate >= currentDate) && ((bufferMonth - currentMonth) == deltaMonth) && ((bufferDate - currentDate) == deltaDay))
        {
            nearestName += " & "s + person[i].name;
        }
        else if ((bufferMonth >= currentMonth) && (bufferDate >= currentDate) && ((bufferMonth - currentMonth) < deltaMonth) && ((bufferDate - currentDate) < deltaDay))
        {
            deltaDay = bufferDate - currentDate;
            deltaMonth = bufferMonth - currentMonth;
            nearestName = person[i].name;
            nearestDate = bufferDate;
            nearestMonth = bufferMonth;
        }
    }
    cout << "Person who has nearest birthday is " << nearestName << " on " << nearestMonth << "/" << nearestDate << std::endl;
}