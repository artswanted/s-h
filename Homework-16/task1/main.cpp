#include <iostream>
#include <string>
#include <ctime>

class Track {
private:
    std::string sTrackName;
    std::string sTrackDate;
    std::string sTrackTime;
public:
    void setTrackName(std::string name){
        sTrackName = name;
    }
    void setTrackDate(std::string date){
        sTrackDate = date;
    }
    void setTrackTime(std::string time){
        sTrackTime = time;
    }

    std::string getTrackName(){
        return sTrackName;
    }
    std::string getTrackDate(){
        return sTrackDate;
    }
    std::string getTrackTime(){
        return sTrackTime;
    }
};

class WinampMediaPlater{
private:
    Track Track_t;
    bool playStatus = false;

    std::string musicList[3][5] = {{"Blinding Lights", "The Twist", "Mack the Knife",
                                                                                             "How Do I Live", "Macarena"},
                                   {"29 November 2019", "19 September 1960", "23 July 1970", "19 September 2000", "23 July 1971"},
                                   {"202", "147", "252", "202", "412"}};
    int playedTrack = 0;
    bool trackPause = false;
public:
    void play(std::string trackName){
        if (!playStatus){
            //std::string result = playTrack(trackName);
            playTrack(trackName);
            std::string result = Track_t.getTrackName();
            std::cout << (result == "null" ? "Wrong track name!" : result + " is playing.\n");
            if (result != "null"){
                trackTime();
                trackDate();
                playStatus = true;
            }
        }
    }

    void pause (){
        pauseTrack();
    }

    void stop(){
        if (playStatus){
            std::cout << "Stopped!";
            playStatus = false;
        }
    }

    void next(){
        std::cout << getNextTrack() << std::endl;
        trackTime();
        trackDate();
    }

    std::string getNextTrack()
    {
        std::srand(time(0));
        int randTrackNo = rand() % 4;
        playedTrack = randTrackNo;
        return musicList[0][randTrackNo];
    }

    void playTrack(std::string trackName){
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
                        Track_t.setTrackName(soundName);
                        Track_t.setTrackDate(musicList[1][playedTrack]);
                        Track_t.setTrackTime(musicList[2][playedTrack]);
                        //return soundName;
                    }
                }
            }
            if (!trackFound) {
                Track_t.setTrackName("null");
            }
            //return "null";
        }
        else {
            trackPause = false;
            Track_t.setTrackName(musicList[0][playedTrack]);
            //return musicList[0][playedTrack];
        }

    }

    void trackDate(){
        //std::cout << musicList[1][playedTrack] << " created date." << std::endl;
        std::cout << Track_t.getTrackDate() << " created date." << std::endl;
    }

    void trackTime(){
        //std::cout << musicList[2][playedTrack] << " total track time." << std::endl;
        std::cout << Track_t.getTrackTime() << " total track time." << std::endl;
    }

    void pauseTrack(){
        if (!trackPause){
            trackPause = true;
            std::cout << "Pause!";
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
            std::cin.ignore();
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