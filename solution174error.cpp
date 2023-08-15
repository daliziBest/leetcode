//有点类似134题 gas station
//1先搞清楚确定路径后如何计算minimum health
//2由1扩展出动态规划
//不过本代码思路细节有问题，设计的转移方程无法保证解的正确：xn的minhealth不一定能从xn-1的minhealth得到，因而无法使用动态规划

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<int> temp(n, 0);
        vector<vector<int>> minHealth(m, temp);
        vector<vector<int>> currentHealth(m, temp);

        int minHealth1, minHealth2, currentHealth1, currentHealth2;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i - 1 >= 0 && j - 1 >= 0) {
                    //from up
                    currentHealth1 = currentHealth[i - 1][j] + dungeon[i][j];
                    if (currentHealth1 > 0) {
                        minHealth1 = minHealth[i - 1][j]; 
                    } else {
                        minHealth1 = minHealth[i - 1][j] + (1 - currentHealth1);
                        currentHealth1 = 1;
                    }
                    //from left
                    currentHealth2 = currentHealth[i][j - 1] + dungeon[i][j];
                    if (currentHealth2 > 0) {
                        minHealth2 = minHealth[i][j - 1];
                    } else {
                        minHealth2 = minHealth[i][j - 1] + (1 - currentHealth2);
                        currentHealth2 = 1;
                    }
                    //compare
                    if (minHealth1 < minHealth2) {
                        minHealth[i][j] = minHealth1;
                        currentHealth[i][j] = currentHealth1;
                    } else {
                        minHealth[i][j] = minHealth2;
                        currentHealth[i][j] = currentHealth2;
                    }
                } else if (i - 1 >= 0) {
                    currentHealth1 = currentHealth[i - 1][j] + dungeon[i][j];
                    if (currentHealth1 > 0) {
                        minHealth[i][j] = minHealth[i - 1][j];
                        currentHealth[i][j] = currentHealth1;
                    } else {
                        minHealth[i][j] = minHealth[i - 1][j] + (1 - currentHealth1);
                        currentHealth[i][j] = 1;
                    }
                } else if (j - 1 >= 0) {
                    currentHealth2 = currentHealth[i][j - 1] + dungeon[i][j];
                    if (currentHealth2 > 0) {
                        minHealth[i][j] = minHealth[i][j - 1];
                        currentHealth[i][j] = currentHealth2;
                    } else {
                        minHealth[i][j] = minHealth[i][j - 1] + (1 - currentHealth2);
                        currentHealth[i][j] = 1;
                    }
                } else {
                    if (dungeon[i][j] > 0) {
                        minHealth[i][j] = 1;
                        currentHealth[i][j] = dungeon[i][j] + 1;
                    } else {
                        minHealth[i][j] = 1 - dungeon[i][j];
                        currentHealth[i][j] = 1;
                    }
                }
            }
        }

        return minHealth[m - 1][n - 1];
    }
};