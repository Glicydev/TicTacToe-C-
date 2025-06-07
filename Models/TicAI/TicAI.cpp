//
// Created by ludov on 06.06.2025.
//

#include "TicAI.h"
#include "../../structs/CaseScore.cpp"

#include <numeric>

double TicAI::GetMoveScore(const TicTacToe& ticTacToe, char player) const {

    // Init
    const vector<int> emptyCases = ticTacToe.GetEmptyCases();
    int varianceRange = _maxVariance - _minVariance + 1;
    int baseVariance = rand() % varianceRange + _minVariance;

    // Donne plus de poids à la stratégie quand la partie avance
    double weight = 1.0 - (emptyCases.size() / ticTacToe.Size);

    int variance = static_cast<int>(baseVariance * weight);    TicTacToe copy = ticTacToe;
    vector<double> futurePoints;
    player = player == 'X' ? 'O' : 'X';

    // Check points
    if (emptyCases.empty()) {
        return 0;
    }
    if (ticTacToe.CheckWin('X')) {
        return _punishment;
    }
    if (ticTacToe.CheckWin('O')) {
        return _reward;
    }

    // Get the points because it's not finished
    for (const int emptyCase : emptyCases) {
        copy.Plate[emptyCase] = player;

        double score = GetMoveScore(copy, player);
        futurePoints.push_back(score);

        copy = ticTacToe;
    }

    // Return
    return accumulate(futurePoints.begin(), futurePoints.end(), 0.0) + variance;
}

int TicAI::GetBestMove() {
    char player = 'O';
    TicTacToe copy = _ticTacToe;
    vector<int> emptyCases = _ticTacToe.GetEmptyCases();
    vector<CaseScore> casePoints;
    int absMove = GetAbsoluteMove('O');

    if (absMove < 0) {
        absMove = GetAbsoluteMove('X');
    }

    if (absMove >= 0) {
        return absMove;
    }

    for (int emptyCase : emptyCases) {
        copy.Plate[emptyCase] = player;

        double score = GetMoveScore(copy, player);
        CaseScore cs = {emptyCase, score};
        // cout << cs.index << ": " << cs.score << endl;

        casePoints.push_back(cs);

        copy = _ticTacToe;
    }

    CaseScore bestCase = casePoints.front();

    for (const CaseScore cs : casePoints) {
        if (cs.score > bestCase.score) {
            bestCase = cs;
        }
    }

    return bestCase.index;
}

int TicAI::GetAbsoluteMove(char player) {
    int move = -1;

    for (const WinningPattern& pattern : _ticTacToe.WinningPatterns) {
        if (_ticTacToe.GetNbOfCharInPattern(player, pattern) == 2) {
            move = _ticTacToe.GetEmptyCaseInPattern(pattern);
        }
    }

    return move;
}
