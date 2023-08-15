//递归

class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.at(0).size();
        int remains = 0;
        int starti;
        int startj;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != -1) {
                    remains++;
                }
                if (grid[i][j] == 1) {
                    starti = i;
                    startj = j;
                }
            }
        }

        return myUnique(grid, starti, startj, remains);
    }

private:
    //[starti, startj]一定可以落子
    int myUnique(vector<vector<int>>& grid, int starti, int startj, int remains) {
        //base case
        if (grid[starti][startj] == 2 && remains == 1) {
            return 1;
        }
        if (grid[starti][startj] == 2 && remains > 1) {
            return 0;
        }

        //core code
        int m = grid.size();
        int n = grid.at(0).size();
        int count = 0;
        grid[starti][startj] = -1;
        if (starti - 1 >= 0 && grid[starti - 1][startj] != -1) {
            count += myUnique(grid, starti - 1, startj, remains - 1);
        }
        if (starti + 1 < m && grid[starti + 1][startj] != -1) {
            count += myUnique(grid, starti + 1, startj, remains - 1);
        }
        if (startj - 1 >= 0 && grid[starti][startj - 1] != -1) {
            count += myUnique(grid, starti, startj - 1, remains - 1);
        }
        if (startj + 1 < n && grid[starti][startj + 1] != -1) {
            count += myUnique(grid, starti, startj + 1, remains - 1);
        }

        grid[starti][startj] = 0;

        return count;

    }
};