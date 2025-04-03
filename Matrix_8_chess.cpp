#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int r = 0, c = 0, count = 0;

        // Find the rook's position
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == 'R') {
                    r = i; // row position of the rook
                    c = j; // column position of the rook
                }
            }
        }

        // Check row to the left of the rook
        for (int j = c - 1; j >= 0; j--) {
            if (board[r][j] == 'p') {
                count++;
                break; // Stop if pawn is captured
            }
            if (board[r][j] == 'B') {
                break; // Stop if bishop blocks
            }
        }

        // Check row to the right of the rook
        for (int j = c + 1; j < board[0].size(); j++) {
            if (board[r][j] == 'p') {
                count++;
                break; // Stop if pawn is captured
            }
            if (board[r][j] == 'B') {
                break; // Stop if bishop blocks
            }
        }

        // Check column above the rook
        for (int i = r - 1; i >= 0; i--) {
            if (board[i][c] == 'p') {
                count++;
                break; // Stop if pawn is captured
            }
            if (board[i][c] == 'B') {
                break; // Stop if bishop blocks
            }
        }

        // Check column below the rook
        for (int i = r + 1; i < board.size(); i++) {
            if (board[i][c] == 'p') {
                count++;
                break; // Stop if pawn is captured
            }
            if (board[i][c] == 'B') {
                break; // Stop if bishop blocks
            }
        }

        return count;
    }
};

int main() {
    // Define the chessboard using characters instead of strings
    vector<vector<char>> board = {
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', 'p', '.', '.', '.', '.'},
        {'.', '.', '.', 'R', '.', '.', '.', 'p'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', 'p', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'}
    };

    //     vector<vector<char>> board = {
    //     {'.', '.', '.', '.', '.', '.', '.', '.'},
    //     {'.', '.', '.', 'p', '.', '.', '.', '.'},
    //     {'.', '.', '.', 'p', '.', '.', '.', '.'},
    //     {'p', 'p', '.', 'R', '.', 'p', 'B', '.'},
    //     {'.', '.', '.', '.', '.', '.', '.', '.'},
    //     {'.', '.', '.', 'B', '.', '.', '.', '.'},
    //     {'.', '.', '.', 'p', '.', '.', '.', '.'},
    //     {'.', '.', '.', '.', '.', '.', '.', '.'}
    // };

    //     vector<vector<char>> board = {
    //     {'.', '.', '.', '.', '.', '.', '.', '.'},
    //     {'.', 'p', 'p', 'p', 'p', 'p', '.', '.'},
    //     {'.', 'p', 'p', 'B', 'p', 'p', '.', '.'},
    //     {'.', 'p', 'B', 'R', 'B', 'p', '.', '.'},
    //     {'.', 'p', 'p', 'B', 'p', 'p', '.', '.'},
    //     {'.', 'p', 'p', 'p', 'p', 'p', '.', '.'},
    //     {'.', '.', '.', '.', '.', '.', '.', '.'},
    //     {'.', '.', '.', '.', '.', '.', '.', '.'}
    // };

    // Create a Solution object
    Solution sol;
    
    // Get the number of pawns the rook can capture
    int result = sol.numRookCaptures(board);
    
    // Output the result
    cout << "Number of pawns the rook can capture: " << result << endl; // Expected output: 3

    return 0;
}
