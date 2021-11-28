#include <iostream>
#include <string>

class Track {
private:
    std::string musicList[3][5] = {{"Blinding Lights", "The Twist", "Mack the Knife",
                                     "How Do I Live", "Macarena"},
                                   {"29 November 2019", "19 September 1960", "23 July 1970", "19 September 2000", "23 July 1971"},
                                   {"202", "147", "252", "202", "412"}};
    int playedTrack = 0;
    bool trackPause = false;
public:
    std::string getNextTrack()
    {
        return musicList[1][1];
    }

    std::string playTrack(std::string trackName){
        if (!trackPause){
            bool trackFound = false;
            for (int i = 0; i < 5; i++){
                std::string soundName = musicList[0][i];
                if (trackName.size() == soundName.size()){
                    for (int j = 0; j < trackName.size(); j++){
                        if (trackName[j] != soundName[j]){
                            trackFound = false;
                            break;
                        } else {
                            trackFound = true;
                        }
                    }
                    if (trackFound){
                        playedTrack = i;
                        return soundName;
                    }
                }
            }
            return "null";
        }
        else {
            trackPause = false;
            return musicList[0][playedTrack];
        }

    }

    void trackDate(){
        std::cout << musicList[1][playedTrack] << " created date." << std::endl;
    }

    void trackTime(){
        std::cout << musicList[2][playedTrack] << " total track time." << std::endl;
    }

    void pauseTrack(){
        if (!trackPause){
            trackPause = true;
            std::cout << "Pause!";
        }
    }
};

class WinampMediaPlater{
private:
    Track Track_t;
    bool playStatus = false;
public:
    void play(std::string trackName){
        if (!playStatus){
            std::string result = Track_t.playTrack(trackName);
            std::cout << (result == "null" ? "Wrong track name!" : result + " is playing.\n");
            if (result != "null"){
                Track_t.trackTime();
                Track_t.trackDate();
                playStatus = true;
            }
        }
    }

    void pause (){
        Track_t.pauseTrack();
    }

    void stop(){
        if (playStatus){
            std::cout << "Stopped!";
            playStatus = false;
        }
    }

    void next(){
       std::cout << Track_t.getNextTrack();
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
            std::getline(std::cin, trackName) ;
            WinPlayer.play(trackName);
        } else if ("pause" == command){
            WinPlayer.pause();
        } else if ("next" == command){
            WinPlayer.next();
        } else if ("stop" == command){
            WinPlayer.stop();
        } else if ("exit" == command){
            break;
        }else{
            std::cout << "Wrong input!";
        }
    } while (true);
    return 0;
}
