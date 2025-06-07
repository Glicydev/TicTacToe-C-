//
// Created by ludov on 06.06.2025.
//

#ifndef GAME_H
#define GAME_H
#include "../../Models/TicAI/TicAI.h"
#include "../../Models/TicTacToe/TicTacToe.h"


class TicTacToeGame {
private:
    TicTacToe _ticTacToe;
    TicAI _ticAI;
    bool _finished;
    char _winner;

    void End(bool& playerStart);
    void MakePlayerPlay();
    void MakeIaPlay();
    bool AskStart();
    void CheckWinner();

public:
    TicTacToeGame(const int& size)
        : _ticTacToe(size), _ticAI(_ticTacToe, -10, 10, -10, 10), _finished(false) { }

    void Start();
};



#endif //GAME_H
