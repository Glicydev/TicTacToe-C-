#include <iostream>

#include "Managers/TicTacToeGame/TicTacToeGame.h"
#include "Models/TicAI/TicAI.h"
#include "Models/TicTacToe/TicTacToe.h"
using namespace  std;


int main() {
    TicTacToeGame game = TicTacToeGame(3);
    game.Start();

    return 0;
}