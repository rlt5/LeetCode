// 130. Surrounded Regions
// Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
// A region is captured by flipping all 'O's into 'X's in that surrounded region.

// Example:
// X X X X
// X O O X
// X X O X
// X O X X
// After running your function, the board should be:

// X X X X
// X X X X
// X X X X
// X O X X
// Explanation:

// Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.

#include <vector>
#include <iostream>
using namespace std;
class Solution{
    public:

        void recursiveFlip(vector<vector<char>>& board, int y, int x, int rows, int cols){
            if ( board[y][x] == 'O' ){
                board[y][x] = 'X';
                if ( 0 < y ) recursiveFlip(board, y-1, x, rows, cols );
                if ( y < rows-1 ) recursiveFlip(board, y+1, x, rows, cols );
                if ( 0 < x ) recursiveFlip(board, y, x-1, rows, cols );
                if ( x < cols-1 ) recursiveFlip(board, y, x+1, rows, cols );
            }
        }

        void solve(vector<vector<char>>& board){
            if ( board.empty() ) return;
            int rows = board.size();
            int cols = board[0].size();

            vector<vector<char>> newBoard = board;

            for ( int x = 0; x < cols; x++){
                recursiveFlip(newBoard,0,x,rows,cols);
                recursiveFlip(newBoard,rows-1,x,rows,cols);
            }
            for ( int y = 0; y < rows; y++){
                recursiveFlip(newBoard,y,0,rows,cols);
                recursiveFlip(newBoard,y,cols-1,rows,cols);
            }

            for ( int x = 0; x < cols; x++ ){
                for ( int y = 0; y < rows; y++ ){
                    if ( board[y][x] == newBoard[y][x] ){
                        board[y][x] = 'X';
                    } else {
                        board[y][x] = 'O';
                    }
                }
            }
        }
};

void printBoard(vector<vector<char>>& board){
    cout << "Print Board" << endl;
    for ( vector<char> row : board ){
        for ( char c : row ){
            cout << c << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    Solution s;
    vector<vector<vector<char>>> boards;
    vector<vector<char>> board;
    char myChars1[] = {'X','X','X','X'};
    char myChars2[] = {'X','O','O','X'};
    char myChars3[] = {'X','X','O','X'};
    char myChars4[] = {'X','O','X','X'};
    vector<char> row1(myChars1,myChars1 + 4);
    vector<char> row2(myChars2,myChars2 + 4);
    vector<char> row3(myChars3,myChars3 + 4);
    vector<char> row4(myChars4,myChars4 + 4);
    board.push_back(row1);
    board.push_back(row2);
    board.push_back(row3);
    board.push_back(row4);
    boards.push_back(board);
    for ( vector<vector<char>> board : boards ){
        cout << "BEFORE" << endl;
        printBoard(board);
        s.solve(board);
        cout << "AFTER" << endl;
        printBoard(board);
    }
    // Solution s;
    // vector<vector<vector<char>>> boards;
    // vector<vector<char>> board;
    // char myChars1[] = {'X'};
    // char myChars2[] = {'O'};
    // char myChars3[] = {'X'};
    // char myChars4[] = {'X'};
    // vector<char> row1(myChars1,myChars1+1);
    // vector<char> row2(myChars2,myChars2+1);
    // vector<char> row3(myChars3,myChars3+1);
    // vector<char> row4(myChars4,myChars4+1);
    // board.push_back(row1);
    // board.push_back(row2);
    // board.push_back(row3);
    // board.push_back(row4);

    // boards.push_back(board);

    // for ( vector<vector<char>> board : boards ){
    //     cout << "BEFORE" << endl;
    //     printBoard(board);
    //     s.solve(board);
    //     cout << "AFTER" << endl;
    //     printBoard(board);
    // }    
}