//类似130，找出所有的连通集
//找每个连通集时，使用BFS思想
//使用queue


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int numOfIsland = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    numOfIsland++;
                    markConnected(grid, i, j);
                }
            }
        }

        return numOfIsland;
    }

private:
    void markConnected(vector<vector<char>>& grid, int m, int n) {
        queue<pair<int, int>> toDeal;
        grid[m][n] = 'D';
        toDeal.push({m, n});
        while (!toDeal.empty()) {
            pair<int, int> temp = toDeal.front();
            toDeal.pop();
            int i = temp.first;
            int j = temp.second; 
            if (i - 1 >= 0 && grid[i - 1][j] == '1') {
                grid[i - 1][j] = 'D';
                toDeal.push({i - 1, j});
            }
            if (i + 1 < grid.size() && grid[i + 1][j] == '1') {
                grid[i + 1][j] = 'D';
                toDeal.push({i + 1, j});
            }
            if (j - 1 >= 0 && grid[i][j - 1] == '1') {
                grid[i][j - 1] = 'D';
                toDeal.push({i, j - 1});
            }
            if (j + 1 < grid[0].size() && grid[i][j + 1] == '1') {
                grid[i][j + 1] = 'D';
                toDeal.push({i, j + 1});
            }
        }
    }
};