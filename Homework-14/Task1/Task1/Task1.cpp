#include <iostream>
#include <map>
#include <ctime>
#include <string>
#include <iomanip>

int total_jobs = 0;
//в студии 2019 _CRT_SECURE_NO_WARNINGS нужно чтобы использовать std::localtime, либо переходить на localtime_s, и не понятно почему вроде как в свежем уроке, учат тому что устарело.

void print_tracking(std::map <int, double>& trackingTimeArray) {
    if (trackingTimeArray.size() > 0) {
        for (std::map <int, double>::iterator it = trackingTimeArray.begin();
            it != trackingTimeArray.end();
            it++) {
            std::cout << "Job #" << it->first << " , time spend: " << abs(it->second) << " seconds" << std::endl;
        }
    }
    else {
        std::cout << "Job-time list is empty!" << std::endl;
    }
}

void timeLess(std::map <int, double>& trackingTimeArray, std::time_t start_time, std::time_t finish_time, bool& bProgress) {
    double d = std::difftime(start_time, finish_time);
    trackingTimeArray.insert(std::make_pair(total_jobs, d));
    total_jobs += 1;
    bProgress = false;
}

int main()
{
    std::string command;
    std::map <int, double> mTimeTracking;
    std::time_t start_time;
    std::time_t finish_time;
    bool bProgress = false; 

    while (true){
        std::cout << "Input command:" << std::endl;
        std::cin >> command;
        if (command == "begin") {
            if (bProgress) {
                finish_time = std::time(nullptr);
                timeLess(mTimeTracking, start_time, finish_time, bProgress);
            }
            else {
                start_time = std::time(nullptr);
                bProgress = true;
            }
        }
        else if (command == "status") {
            print_tracking(mTimeTracking);
        }
        else if (command == "end") {
            if (!bProgress){
                std::cout << "No timer in progress" << std::endl;
            }
            else {
                finish_time = std::time(nullptr);
                timeLess(mTimeTracking, start_time, finish_time, bProgress);
            }
        }
        else if (command == "exit") {
            std::cout << "Have a nice day!" << std::endl;
            break;
        } else {
            std::cout << "Wrong input!" << std::endl;
        }
    }
}