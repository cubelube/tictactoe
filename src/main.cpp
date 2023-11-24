#include <iostream>

std::string boardSpace[3][3] = {{"1", "2", "3"}, {"4", "5", "6"}, {"7", "8", "9"}};
int row;
int column;
std::string character = "x";
bool tie = false;
std::string player1;
std::string player2;

void printBoard();
void playerEnter();
bool isGameOver();

int main() {

    std::cout << "Name of Player 1: \n";
    getline(std::cin, player1);
    std::cout << "Name of player 2: \n";
    getline(std::cin, player2);

    printBoard();

    while(!isGameOver()) {
        playerEnter();
        isGameOver();
    }

    if((character == "x") && (tie == false)) {
        std::cout << player2 << " wins! \n";
    } else if((character == "o") && (tie == false)) {
        std::cout << player1 << " wins! \n";
    } else {
        std::cout << "The players tied! \n";
    }
    return 0;
}

void printBoard() {
    //std::string boardSpace[3][3] = {{"1", "2", "3"}, {"4", "5", "6"}, {"7", "8", "9"}};
    std::cout << "  |  |  \n";
    std::cout << boardSpace[0][0] << " |" << boardSpace[0][1] << " |" << boardSpace[0][2] << "\n";
    std::cout << "__|__|__ \n";
    std::cout << "  |  |  \n";
    std::cout << boardSpace[1][0] << " |" << boardSpace[1][1] << " |" << boardSpace[1][2] << "\n";
    std::cout << "__|__|__ \n";
    std::cout << "  |  |  \n";
    std::cout << boardSpace[2][0] << " |" << boardSpace[2][1] << " |" << boardSpace[2][2] << "\n";
    std::cout << "  |  |  \n";
}

void playerEnter() {
    int place;

    if(character == "x") {
        std::cout << player1 << " , please enter your placement: \n";
        std::cin >> place;
    } else {
        std::cout << player2 << " , please enter your placement: \n";
        std::cin >> place;
    }

    switch(place) {
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
        default:
            std::cout << "Not a valid input";
    }

    if((character == "x") && (boardSpace[row][column] != "x") && (boardSpace[row][column] != "o")) {
        boardSpace[row][column] = 'x';
        character = "o";
    } else if((character == "o") && (boardSpace[row][column] != "x") && (boardSpace[row][column] != "o")) {
        boardSpace[row][column] = 'o';
        character = "x";
    } else {
        std::cout << "Cannot place character there \n";
        playerEnter();
    }

    printBoard();
}

bool isGameOver() {
    for(int i=0; i<3; i++) {
        if((boardSpace[i][0] == boardSpace[i][1]) && (boardSpace[i][0] == boardSpace[i][2]) || (boardSpace[0][i] == boardSpace[1][i]) && (boardSpace[0][i] == boardSpace[2][i])) {
            return true;
        } else if((boardSpace[0][0] == boardSpace[1][1]) && (boardSpace[1][1] == boardSpace[2][2]) || (boardSpace[0][2] == boardSpace[1][1]) && (boardSpace[1][1] == boardSpace[2][0])) {
            return true;
        }
    }

    for(int i=0; i < 3; i++) {
        for(int j=0; j < 3; j++) {
            if((boardSpace[i][j] != "x") && (boardSpace[i][j] != "o")) {
                return false;
            }
        }
    }

    tie = true;
    return false;
