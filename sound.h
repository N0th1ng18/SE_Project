#ifndef SOUND_H
#define SOUND_H
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <iostream>
using namespace std;

class Sound
{

public:

    Sound();
    ~Sound();
    void load(string path);
    void play(int index);
    void stop();
    void repeat(int index);
    void setVolume(int volume);
    bool isPlaying();
    bool isStopped();

protected:

private:
    QMediaPlayer* music = new QMediaPlayer();
    QMediaPlaylist* playlist = new QMediaPlaylist();
};

#endif // SOUND_H
