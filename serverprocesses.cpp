#include "serverprocesses.h"



ServerProcesses::ServerProcesses()
{


}
bool spawnGameThread(ServerData serverD){
    bool created = false;

    gameThread(serverD); //Create the game thread

    // Update the ThreadContainer
    // Update created if gameThread == ThreadContainer

    return created;
}

bool terminateGameThread(int gameID){

    bool isGameInactive = false;

    //Search for game thread in the database
    // if game thread is terminated change isGameInactive to true

    return isGameInactive;
}

void processMsg(SocketData msg){

    //calls check Validity
    //switch statement based on the msg variable

}

bool checkValidity(){
    bool isValid = false;

    //checks the validity of the connection and encrypting the message
    //called by processMsg

    return isValid;
}
