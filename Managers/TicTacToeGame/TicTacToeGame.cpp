//
// Created by ludov on 06.06.2025.
//

#include <iostream>
#include "TicTacToeGame.h"

using namespace std;

void TicTacToeGame::Start() {
    bool playerStart = AskStart();

    while (true) {
        if (playerStart) {
            _ticTacToe.Display();
            MakePlayerPlay();
            MakeIaPlay();
        }
        else {
            MakeIaPlay();
            _ticTacToe.Display();
            MakePlayerPlay();
        }

        if (_finished) {
            End(playerStart);
        }
    }
}

void TicTacToeGame::End(bool& playerStart) {
    _finished = false;
    _ticTacToe.Reset();

    if (_winner == '/') {
        cout << "It's a tie !" << endl;
    }
    else {
        cout << "The winner is: " << _winner << endl;
    }
    cout << endl;

    playerStart = AskStart();
}

void TicTacToeGame::MakeIaPlay() {
    if (_finished) return;

    int botChoice = _ticAI.GetBestMove();
    _ticTacToe.Place(botChoice, 'O');

    CheckWinner();
}

void TicTacToeGame::MakePlayerPlay() {
    if (_finished) return;

    int choice;

    cout << endl << "Choose where to play:";
    cin >> choice;
    choice--;

    _ticTacToe.Place(choice, 'X');
    CheckWinner();
}

bool TicTacToeGame::AskStart() {
    char input;

    cout << "Do you want to start? (y/n)" << endl;
    cin >> input;

    return input == 'Y' || input == 'y';
}

void TicTacToeGame::CheckWinner() {
    char winner = '/';

    if (_ticTacToe.GetEmptyCases().empty()) {
        _finished = true;
    }
    else if (_ticTacToe.CheckWin('X')) {
        _finished = true;
        winner = 'X';
    }
    else if (_ticTacToe.CheckWin('O')) {
        _finished = true;
        winner = 'O';
    }

    _winner = winner;
}
