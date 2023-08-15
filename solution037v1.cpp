//从所有排列里面找出符合我们要求的那个排列
//recursion+backtracking
//注意vector是char型
//第一次使用goto
/**
 * 这个网站 https://pi.math.cornell.edu/~mec/Summer2009/meerkamp/Site/Introduction.html
 * 有关于sudoku问题更详细的介绍(待阅)
 * **/

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        //find the first element to fill
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    mySolveSudoku(board, i, j);
                    return;
                }
            }
        }

        return;
    }

private:
    //自定义SolveSudoku
    //假定每次传入的数独都是valid
    //[toI, toJ]指向下个待填的位置
    bool mySolveSudoku(vector<vector<char>>& board, int toI, int toJ) {
        //base case
        if (toI == -1 && toJ == -1) {
            return true;
        }

        //find the next element to be filled
        //easy to make a mistake
        //firstly use goto
        int nextI = -1;
        int nextJ = -1;
        for (int j = toJ + 1; j < 9; j++) {
            if (board[toI][j] == '.') {
                nextI = toI;
                nextJ = j;
                goto core;
            }
        }
        for (int i = toI + 1; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    nextI = i;
                    nextJ = j;
                    goto core;
                }
            }
        }           
        
    core:
        //core code
        for (char i = '1'; i <= '9'; i++) {
            if(check(board, i, toI, toJ)) {
                board[toI][toJ] = i;
                if (mySolveSudoku(board, nextI, nextJ)) {
                    return true;
                } else {
                    board[toI][toJ] = '.';
                    continue;
                }
            }
        }


        return false;
    }

    //检查num是否可以填入当前位置
    bool check(vector<vector<char>>& board, char num, int toI, int toJ) {
        //check row
        for (int j = 0; j < 9; j++) {
            if (board[toI][j] == num) {
                return false;
            }
        }

        //check column
        for (int i = 0; i < 9; i++) {
            if (board[i][toJ] == num) {
                return false;
            }
        }

        //check 3*3 sub-box
        int baseI = toI / 3 * 3;
        int baseJ = toJ / 3 * 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[baseI + i][baseJ + j] == num) {
                    return false;
                }
            }
        }

        return true;
    }
};