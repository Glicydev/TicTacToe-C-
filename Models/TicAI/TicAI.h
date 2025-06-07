//
// Created by ludov on 06.06.2025.
//

#ifndef TICAI_H
#define TICAI_H
#include <vector>

#include "../TicTacToe/TicTacToe.h"

using namespace  std;


class TicAI {
private:
    vector<char> _plate;
    TicTacToe& _ticTacToe;
    int _minVariance;
    int _maxVariance;
    int _punishment;
    int _reward;

    double GetMoveScore(const TicTacToe& ticTacToe, char player, int stage) const;
    int GetAbsoluteMove(char player);

public:
    int GetBestMove();
    TicAI(TicTacToe& ticTacToe, int punishment, int reward, int minVar, int maxVar)
        : _ticTacToe(ticTacToe), _punishment(punishment), _reward(reward), _plate(ticTacToe.Plate), _minVariance(minVar), _maxVariance(maxVar)
    { }
};



#endif //TICAI_H
