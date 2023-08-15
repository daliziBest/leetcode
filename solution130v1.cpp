//从border出发, 找出所有can't be flipped的'O', 将其修改为'N', 最后再遍历一遍整个矩阵，清扫战场
//利用queue
//queue的pop()无返回值

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        //从border出发, 找出所有can't be flipped的'O', 将其修改为'N'
        for (int i = 0; i < n; i++) {
            if (board[0][i] == 'O') {
                findO(board, 0, i);
            }
        }
        for (int i = 1; i < m; i++) {
            if (board[i][0] == 'O') {
                findO(board, i, 0);
            }
        }
        for (int i = 1; i < m; i++) {
            if (board[i][n - 1] == 'O') {
                findO(board, i, n - 1);
            }
        }
        for (int i = 1; i < n - 1; i++) {
            if (board[m - 1][i] == 'O') {
                findO(board, m - 1, i);
            }
        }

        //再遍历一遍整个矩阵，清扫战场
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'N') {
                    board[i][j] = 'O';
                }
            }
        }
    }

private:
    void findO(vector<vector<char>>& board, int i, int j) {
        queue<pair<int, int>> toDeal;
        board[i][j] = 'N';
        toDeal.push({i, j});
        while (!toDeal.empty()) {
            pair<int, int> temp = toDeal.front();
            toDeal.pop();
            int m = temp.first;
            int n = temp.second;
            if (m - 1 >= 0 && board[m - 1][n] == 'O') {
                board[m - 1][n] = 'N';
                toDeal.push({m - 1, n});
            }
            if (m + 1 < board.size() && board[m + 1][n] == 'O') {
                board[m + 1][n] = 'N';
                toDeal.push({m + 1, n});
            }
            if (n - 1 >= 0 && board[m][n - 1] == 'O') {
                board[m][n - 1] = 'N';
                toDeal.push({m, n - 1});
            }
            if (n + 1 < board[0].size() && board[m][n + 1] == 'O') {
                board[m][n + 1] = 'N';
                toDeal.push({m, n + 1});
            }
        }
    }
};