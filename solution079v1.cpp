//递归

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (myExist(board, i, j, word, 0)) {
                    return true;
                }
            }
        }

        return false;
    }

private:
    //(i,j)一定是还未访问过的字符
    bool myExist(vector<vector<char>>& board, int i, int j, string word, int x) {
        //base case
        if (board[i][j] != word.at(x)) {
            return false;
        }

        if (board[i][j] == word.at(x) && x == word.size() - 1) {
            return true;
        }

        //core code
        int m = board.size();
        int n = board[0].size();
        board[i][j] = '.';
        if (i - 1 >= 0 && board[i - 1][j] != '.') {
            if (myExist(board, i - 1, j, word, x + 1)) {
                return true;
            }
        }
        if (i + 1 < m && board[i + 1][j] != '.') {
            if (myExist(board, i + 1, j, word, x + 1)) {
                return true;
            }
        }
        if (j - 1 >= 0 && board[i][j - 1] != '.') {
            if (myExist(board, i, j - 1, word, x + 1)) {
                return true;
            }
        }
        if (j + 1 < n && board[i][j + 1] != '.') {
            if (myExist(board, i, j + 1, word, x + 1)) {
                return true;
            }
        }

        board[i][j] = word.at(x);
        return false;
    }
};