//
// Created by ludov on 06.06.2025.
//

#ifndef TICTACTOE_H
#define TICTACTOE_H
#include <cmath>
#include <iostream>
#include <vector>

#include "../WinningPattern/WinningPattern.h"

using namespace std;

class TicTacToe {
private:
    int _nbElements;

    void GetWinningPatterns();
    void BuildPlate();

public:
    int Size;
    vector<char> Plate;
    string Player = "X";
    vector<WinningPattern> WinningPatterns;

    TicTacToe(const int size) {
        Size = size;
        _nbElements = pow(size, 2);
        BuildPlate();
        GetWinningPatterns();
    }

    void Display() const;
    vector<int> GetEmptyCases() const;
    int GetEmptyCaseInPattern(const WinningPattern& pattern) const;
    int GetNbOfChar(char player) const;
    int GetNbOfCharInPattern(char player, WinningPattern winningPattern) const;
    void Place(int index, char player);
    bool CheckWin(char player) const;
    void Reset();
};



#endif //TICTACTOE_H
