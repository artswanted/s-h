#include <iostream>
#include <string>

class Track {
private:
    std::string musicList[3][5] = {{"Blinding Lights", "The Twist", "Mack the Knife",
                                     "How Do I Live", "Macarena"},
                                   {"29 November 2019", "19 September 1960", "23 July 1970", "19 September 2000", "23 July 1971"},
                                   {"202", "147", "252", "202", "412"}};
public:
    std::string getNextTrack()
    {
        return musicList[1][1];
    }

    std::string trackChecker(std::string trackName){
        return;
    }
};

class WinampMediaPlater{
private:
    Track Track_t;
    int currentTrack = 0;
public:
    void play(std::string trackName){
        if (currentTrack == 0){
            std::string name = Track_t.trackChecker(trackName);
            if (name != "null"){
                currentTrack = 1;
                std::cout << name;
            } else if (name == "null"){
                std::cout << "Track is nor found!";
            }
        }
    }

};

int main() {
    WinampMediaPlater WinPlayer;
    std::string command, trackName;
    do {
        std::cout << "Input command:";
        std::cin >> command;
        if ("play" == command) {
            std::cout << "Input trask name:";
            std::cin >> trackName;
            WinPlayer.play(trackName);
        } else if ("pause" == command){

        } else if ("next" == command){

        } else if ("stop" == command){

        } else if ("exit" == command){
            break;
        }else{
            std::cout << "Wrong input!";
        }
    } while (true);
    return 0;
}
