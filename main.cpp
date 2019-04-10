#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    static int MAX_GAME_THREADS = 5;
    int current_game_Threads = 0;

    return a.exec();
}
