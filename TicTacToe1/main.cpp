#include "TicTacToe/Game.h"
#include "gameInterface/Application.h"
#include "HangMan/hangMan.h"
#include "cstdlib"
#include "ctime"
int main()
{
    srand(time(0));
    Game game;
    hangMan hang_Man;
    Application a;
    a.addGame(game);
    a.addGame(hang_Man);
    a.start();
    return 0;
}
