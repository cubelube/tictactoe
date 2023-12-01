#include <iostream>
#include <vector>
#include <cstdlib>

#include "tictactoe.h"

void TicTacToe::playGame() {

    // Figure out if playing against human or bot

    std::string humanorbot;

    TicTacToe playgame;

    playgame.printBoard();

    std::cout << "Vs human or bot?";
    std::cin >> humanorbot;

    if(humanorbot == "human") {
        while(!playgame.isGameOver()) {
            playgame.playerEnter();
            playgame.isGameOver();
        }
    } else {
        while(!playgame.isGameOver()) {
            playgame.playAgainstBot();
            playgame.isGameOver();
        }
    }

    // Decide who gets winning message (or tie) (currently broken)
    if((character == "X") && (tie == false)) {
        std::cout << "Player 1 wins! \n";
    } else if((character == "O") && (tie == false)) {
        std::cout << "Player 2 wins! \n";
    } else if((character == "X") && (tie == true) || (character == "O") && (tie == true)) {
        std::cout << "The players tied! \n";
    } else {
        std::cout << "Not a valid result";
    }
}

void TicTacToe::printBoard() {
    // prints board 
    std::cout << "     |     |  \n";
    std::cout << "  " << boardSpace[0][0] << "  |  " << boardSpace[0][1] << "  |  " << boardSpace[0][2] << "\n";
    std::cout << "_____|_____|_____ \n";
    std::cout << "     |     |  \n";
    std::cout << "  " << boardSpace[1][0] << "  |  " << boardSpace[1][1] << "  |  " << boardSpace[1][2] << "\n";
    std::cout << "_____|_____|_____ \n";
    std::cout << "     |     |  \n";
    std::cout << "  " << boardSpace[2][0] << "  |  " << boardSpace[2][1] << "  |  " << boardSpace[2][2] << "\n";
    std::cout << "     |     |  \n";
}

void TicTacToe::playerEnter() {
    // placement variable
    int place;

    if(character == "X") {
        std::cout << "Player 1, please enter your placement: \n";
        std::cin >> place;
    } else {
        std::cout << "Player 2, please enter your placement: \n";
        std::cin >> place;
    }

    // gets array indices from placement
    getRowsAndColumns(place);

    // places character if valid, if not asks for placement again
    if((character == "X") && (boardSpace[row][column] != "X") && (boardSpace[row][column] != "O")) {
        boardSpace[row][column] = 'X';
        character = "O";
    } else if((character == "O") && (boardSpace[row][column] != "X") && (boardSpace[row][column] != "O")) {
        boardSpace[row][column] = 'O';
        character = "X";
    } else {
        std::cout << "Cannot place character there \n";
        playerEnter();
    }

    printBoard();
}

void TicTacToe::playAgainstBot() {
    // placement variable
    int place;

    // if human, get placement & place it
    if(character == "X") {
        std::cout << "Please enter your placement: ";
        std::cin >> place;

        getRowsAndColumns(place);

    if((boardSpace[row][column] != "X") && (boardSpace[row][column] != "O")) {
        boardSpace[row][column] = "X";
        character = "O";
    } else { // if placement not valid, ask again
        std::cout << "Cannot place character there";

        playAgainstBot();
    }
    } else { // if not human's turn, get bot response
        // get legal moves
        legalMoves();

        // random number from 0 to choices vector size
        srand((unsigned) time(NULL));
        int random = 0 + (rand() % choices.size());

        // convert choices[random] (string) to choicesRandom (int)
        int choicesRandom = stoi(choices[random]);

        getRowsAndColumns(choicesRandom);

        // place bot selection
        boardSpace[row][column] = "O";
        character = "X"; 
    }

    printBoard();

}

bool TicTacToe::isGameOver() {

    // checks for vertical or horizontal win
    for(int i=0; i<3; i++) {
        if((boardSpace[i][0] == boardSpace[i][1]) && (boardSpace[i][0] == boardSpace[i][2]) || (boardSpace[0][i] == boardSpace[1][i]) && (boardSpace[0][i] == boardSpace[2][i])) {
            return true;
        } else if((boardSpace[0][0] == boardSpace[1][1]) && (boardSpace[1][1] == boardSpace[2][2]) || (boardSpace[0][2] == boardSpace[1][1]) && (boardSpace[1][1] == boardSpace[2][0])) {
            return true;
        }
    }

    // checks for diag win
    for(int i=0; i < 3; i++) {
        for(int j=0; j < 3; j++) {
            if((boardSpace[i][j] != "X") && (boardSpace[i][j] != "O")) {
                return false;
            }
        }
    }

    tie = true;
    return true;
}

// get legal moves and put it in choices vector
void TicTacToe::legalMoves() {
    choices.clear();
    
       for(int i=0; i < 3; i++) {
        for(int j=0; j < 3; j++) {
            if((boardSpace[i][j] != "X") && (boardSpace[i][j] != "O")) {
                choices.push_back(boardSpace[i][j]);
            }
        }
    }
}

// switch statement to get indices for board from selection
void TicTacToe::getRowsAndColumns(int boardChoice) {
    switch(boardChoice) {
        case 1:
            row = 0;
            column = 0;
            break;
        case 2:
            row = 0;
            column = 1;
            break;
        case 3:
            row = 0;
            column = 2;
            break;
        case 4:
            row = 1;
            column = 0;
            break;
        case 5:
            row = 1;
            column = 1;
            break;
        case 6:
            row = 1;
            column = 2;
            break;
        case 7:
            row = 2;
            column = 0;
            break;
        case 8:
            row = 2;
            column = 1;
            break;
        case 9:
            row = 2;
            column = 2;
            break;
    }
}
