//使用公式直接计算C(n-1, n+m-2)会造成数据溢出
//使用递归，耗时太多超出时间限制
//动态规划

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> a(n, 0);
        vector<vector<int>> countGrid(m, a);
        countGrid[0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
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