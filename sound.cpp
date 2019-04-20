#include "sound.h"

Sound::Sound()
{

}

Sound::~Sound()
{
    delete music;
    delete playlist;
}

void Sound::load(string path)
{
    // Creates playlist and adds the media from string
    playlist -> addMedia(QUrl(path.c_str()));
}

void Sound::play(int index)
{
    playlist -> setPlaybackMode(QMediaPlaylist::CurrentItemOnce);
    if(playlist->currentIndex() != index){
        playlist->setCurrentIndex(index);
    }
    //sets the playlist with the media inputed from previous string
    music->setPlaylist(playlist);
    music->play();
}

void Sound::stop()
{
    music->stop();
}

void Sound::repeat(int index)
{
    //qDebug("repeat");
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    if(playlist->currentIndex() != index){
        playlist->setCurrentIndex(index);
    }

    //sets the playlist with the media inputed from previous string
    music->setPlaylist(playlist);
    music->play();
}

void Sound::setVolume(int volume)
{
    //Volume Range (min Volume)0 -> 100(max Volume)
    //Values outside Range will be clamped
    music->setVolume(volume);
}

bool Sound::isPlaying()
{
    if(music->state() == QMediaPlayer::PlayingState)
    {
        return true;
    }

    else {
        return false;
    }
}

bool Sound::isStopped()
{
    if(music->state() == QMediaPlayer::StoppedState)
    {
        return true;
    }

    else {
        return false;
    }
}
