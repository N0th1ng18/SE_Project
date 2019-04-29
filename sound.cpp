#include "sound.h"

/*
 * Description:
 *  Constructor
 *
 * Contributors:
 *  John, Nick
 *
*/
Sound::Sound()
{

}

/*
 * Description:
 *  Destructor
 *
 * Contributors:
 *  John, Nick
 *
*/
Sound::~Sound()
{
    delete music;
    delete playlist;
}

/*
 * Description:
 *  Loads the music path from resource file using variable(s) path
 *
 * Contributors:
 *  John, Nick
 *
*/
void Sound::load(string path)
{
    // Creates playlist and adds the media from string
    playlist -> addMedia(QUrl(path.c_str()));
}

/*
 * Description:
 *  Plays the saved sound using index with variable(s) index
 *
 * Contributors:
 *  John, Nick
 *
*/
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

/*
 * Description:
 *  Stops the current music is playing any
 *
 * Contributors:
 *  John, Nick
 *
*/
void Sound::stop()
{
    music->stop();
}

/*
 * Description:
 *  Repeats the called track using variable(s) index
 *
 * Contributors:
 *  John, Nick
 *
*/
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

/*
 * Description:
 *  Sets the volume for the player using variable(s) volume
 *
 * Contributors:
 *  John, Nick
 *
*/
void Sound::setVolume(int volume)
{
    //Volume Range (min Volume)0 -> 100(max Volume)
    //Values outside Range will be clamped
    music->setVolume(volume);
}

/*
 * Description:
 *  Checks to see if the media player is currently playing a song
 *
 * Contributors:
 *  John, Nick
 *
*/
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

/*
 * Description:
 *  Checks to see if the media player is currently stopped
 *
 * Contributors:
 *  John, Nick
 *
*/
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
