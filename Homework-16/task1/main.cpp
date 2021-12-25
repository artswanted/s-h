#include <iostream>
#include <string>
#include <ctime>
#include <vector>

class Track
{
public:
    std::string name;
    std::string date;
    int duration;
};

class WinampMediaPlater
{
private:
    std::vector <Track> list;
public:
    bool currentPlay = false;
    std::string buffer = "unknown";
    void addTrack ()
    {
        Track NewTrack;
        std::cout << "Please enter a name of the track:" << std::endl;
        std::cin >> NewTrack.name;
        std::time_t t = std::time(nullptr);
        std::tm today = *std::localtime (&t);
        NewTrack.date= std::to_string(today.tm_mon) + "/" + std::to_string(today.tm_mday);
        std::cout << "Please enter a duration of the track:" << std::endl;
        std::cin >> NewTrack.duration;
        list.push_back(NewTrack);
    };
    void play ()
    {
        std::cout << "Please enter a name of the track:" << std::endl;
        std::cin >> std::ws;
        std::getline (std::cin, buffer);
        for (int i = 0; i < list.size(); i++)
        {
            if (buffer == list[i].name)
            {
                std::cout <<"Play";
                currentPlay = true;
            }
        }
        if (!currentPlay) std::cout << "There is no such kind of track" << std::endl;
    };
    void pause ()
    {
        if (currentPlay)
        {
            std::cout << "Track is on pause" << std::endl;
        }
    };
    void next ()
    {
        int currentNumberTrack;
        for (int i = 0; i < list.size(); i++)
        {
            if (buffer == list[i].name) currentNumberTrack = i;
        }
        int newNumberTrack = rand() % (list.size()+1);
        while (newNumberTrack == currentNumberTrack)
        {
            newNumberTrack = rand() % (list.size()+1);
        }
        buffer = list[newNumberTrack].name;
        std::cout << "New song playing " << buffer << std::endl;
    };
    void stop ()
    {
        if(currentPlay){
            currentPlay = false;
            std::cout << "Track is stopped" << std::endl;
        }
    };
};

int main() {
    WinampMediaPlater WinPlayer;
    std::string command, trackName;
    do {
        std::cout << "Input command:";
        std::cin >> command;
        if ("play" == command) {
            WinPlayer.play ();
        } else if ("pause" == command){
            WinPlayer.pause();
        } else if ("next" == command){
            WinPlayer.next();
        } else if ("stop" == command) {
            WinPlayer.stop();
        } else if ("add" == command) {
            WinPlayer.addTrack ();
        } else if ("exit" == command){
            break;
        }else{
            std::cout << "Wrong input!";
        }
    } while (true);
    return 0;
}