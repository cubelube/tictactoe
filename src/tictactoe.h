#include <vector>

class TicTacToe {
    public:
        void playGame();

        /* Unused currently
        std::string player1;
        std::string player2; */

    private:
        void printBoard();
        void playerEnter();
        bool isGameOver();
        void legalMoves();
        void playAgainstBot();
        void getRowsAndColumns(int boardChoice);

        std::string boardSpace[3][3] = {{"1", "2", "3"}, {"4", "5", "6"}, {"7", "8", "9"}};
        int row;
        int column;
        std::string character = "X";
        bool tie = false;
        std::vector<std::string> choices;
        int boardChoice;
};
