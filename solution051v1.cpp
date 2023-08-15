//递归解法，类似数独
//不过效率容易较低，需要仔细优化

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        string s(n, '.');
        vector<string> current(n, s);
        vector<bool> colOccupied(n, false);

        mySolveNQueens(result, current, 0, n, colOccupied);

        return result;
    }
    
private:
    //current表示的棋盘一定是合规的
    void mySolveNQueens(vector<vector<string>>& result, vector<string>& current, int tofill, int num, vector<bool>& colOccupied) {
        int n = current.size();

        //base case
        if (num == 0) {
            result.push_back(current);
            return;
        }
        // if (n * n - tofill < num) {
        //     return;
        // }
        if (n - tofill / n < num) {
            return;
        }

        //core code
        //parse the tofill to [i][j]
        int i = tofill / n;
        int j = tofill % n;
        //current[i][j] = 'Q';
        if (colOccupied.at(j) == false && check(current, i, j)) {
            current[i][j] = 'Q';
            colOccupied.at(j) = true;
            mySolveNQueens(result, current, (tofill / n + 1) * n, num - 1, colOccupied);
            current[i][j] = '.';
            colOccupied.at(j) = false;
        }

        //current[i][j] = '.';
        mySolveNQueens(result, current, tofill + 1, num, colOccupied);
    }

    //仅仅检查[row][col]当前位置的两条对角线是否有queen
    bool check(vector<string>&current, int row, int col) {
        int end = current.size();
        //检查当前行
        // for(int j = 0; j < end; j++) {
        //     if (j == col) {
        //         continue;
        //     }
        //     if (current[row][j] == 'Q') {
        //         return false;
        //     }
        // }
        //检查当前列
        // for(int i = 0; i < end; i++) {
        //     if (i == row) {
        //         continue;
        //     }
        //     if (current[i][col] == 'Q') {
        //         return false;
        //     }
        // }

        //检查四个斜线
        int i = row - 1;
        int j = col - 1;
        while (i >= 0 && j >= 0) {
            if (current[i][j] == 'Q') {
                return false;
            }
            i--;
            j--;
        }

        i = row - 1;
        j = col + 1;
        while (i >= 0 && j < end) {
            if (current[i][j] == 'Q') {
                return false;
            }
            i--;
            j++;
        }

        i = row + 1;
        j = col - 1;
        while (i < end && j >= 0) {
            if (current[i][j] == 'Q') {
                return false;
            }
            i++;
            j--;
        }

        i = row + 1;
        j = col + 1;
        while (i < end && j < end) {
            if (current[i][j] == 'Q') {
                return false;
            }
            i++;
            j++;
        }

        return true;
    }
};