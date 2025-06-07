//
// Created by ludov on 06.06.2025.
//

#include "TicTacToe.h"

#include <algorithm>

using namespace std;

///
///Get all the winning patterns to check
///
void TicTacToe::GetWinningPatterns() {
    WinningPatterns.clear();

    // Check Rows
    for (int i = 0; i < _nbElements; i+=Size) {
        vector<int> rowPatternVector;
        for (int j = 0; j < Size; j++) {
            rowPatternVector.push_back(i + j);
        }

        WinningPattern rowPattern = WinningPattern(rowPatternVector);
        WinningPatterns.push_back(rowPattern);
    }

    // Check Cols
    for (int i = 0; i < Size; i++) {
        vector<int> colPatternVector;
        for (int j = 0; j < Size; j++) {
            colPatternVector.push_back(i + j * Size);
        }

        WinningPattern rowPattern = WinningPattern(colPatternVector);

        WinningPatterns.push_back(rowPattern);
    }

    // Get diags
    vector<int> diagVector;
    for (int i = 0; i < Size; ++i) {
        diagVector.push_back(i * Size + i);
    }
    WinningPattern diagPattern = WinningPattern(diagVector);
    WinningPatterns.push_back(diagPattern);

    // Second diag
    vector<int> secondDiagVector;
    for (int i = 0; i < Size; ++i) {
        secondDiagVector.push_back(i * Size + (Size - 1 - i));
    }
    WinningPattern secondDiagPattern = WinningPattern(secondDiagVector);
    WinningPatterns.push_back(secondDiagPattern);
}

///
/// Build the starting plate
///
void TicTacToe::BuildPlate() {
    for (int i = 0; i < _nbElements; i++) {
        Plate.emplace_back(' ');
    }
}

///
/// Get all the empty cases of the tic tac toe
///
vector<int> TicTacToe::GetEmptyCases() const {
    vector<int> emptyCases;

    for (int i = 0; i < _nbElements; i++) {
        if (Plate[i] == ' ') {
            emptyCases.push_back(i);
        }
    }

    return emptyCases;
}

///
/// Display the plate in the terminal
///
void TicTacToe::Display() const {
    for (int i = 0; i < _nbElements; i++) {
            cout << "|" << Plate[i] << "|";

            if ((i + 1) % Size == 0 && i != 0) {
                cout << endl;
            }
        }
}

///
/// Places an character on the choosed index
///
void TicTacToe::Place(int index, char player) {
    Plate[index] = player;
}

int TicTacToe::GetEmptyCaseInPattern(const WinningPattern& pattern) const {
    for (const int& index : pattern.Pattern) {
        if (Plate[index] == ' ') {
            return index;
        }
    }

    return -1;
}

int TicTacToe::GetNbOfChar(char player) const {
    int hasCharMax = 0;

    for (const WinningPattern& winningPattern : WinningPatterns) {
        int hasChar = 0;

        for (int index : winningPattern.Pattern) {
            if (Plate[index] == player) {
                hasChar++;
            }
        }

        hasCharMax = max(hasCharMax, hasChar);
    }

    return hasCharMax;
}

int TicTacToe::GetNbOfCharInPattern(char player, WinningPattern winningPattern) const {
    return count_if(winningPattern.Pattern.begin(), winningPattern.Pattern.end(),
                    [&](int index) { return Plate[index] == player; });
}

///
/// Check if the player in parameter has won
///
/// @param player The player to check
/// @return The state of the win (boolean)
bool TicTacToe::CheckWin(char player) const {
    bool win = false;

    for (const WinningPattern& winningPattern : WinningPatterns) {
        if (GetNbOfCharInPattern(player, winningPattern) == 3) {
            win = true;
            break;
        }
    }

    return win;
}

void TicTacToe::Reset() {
    for (int i = 0; i < _nbElements; i++) {
        Plate[i] = ' ';
    }
}
