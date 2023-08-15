//和062类似

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid.at(0).size();
        vector<int> a(n, 0);
        vector<vector<int>> countGrid(m, a);
        countGrid[0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    countGrid[i][j] = 0;
                    continue;
                }
                if (i - 1 >= 0) {
                    countGrid[i][j] += countGrid[i - 1][j];
                }
                if (j - 1 >= 0) {
                    countGrid[i][j] += countGrid[i][j - 1];
                }
            }
        }

        return countGrid[m - 1][n - 1];
    }
};