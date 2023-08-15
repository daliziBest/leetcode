//有点类似134题 gas station
//先搞清楚确定路径后如何计算minimum health!!!!  从尾向头grow，逆推
//动态规划

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<int> temp(n, 0);
        vector<vector<int>> minHealth(m, temp);
        //vector<vector<int>> remainHealth(m, temp);

        
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (j + 1 < n && i + 1 < m) {
                    int temp = minHealth[i][j + 1] < minHealth[i + 1][j] ? minHealth[i][j + 1] : minHealth[i + 1][j];
                    if (dungeon[i][j] >= temp) {
                        minHealth[i][j] = 1;
                        //remainHealth[i][j] = 1 + dungeon[i][j];
                    } else {
                        minHealth[i][j] = temp - dungeon[i][j];
                    }
                } else if (j + 1 < n) {
                    if (dungeon[i][j] >= minHealth[i][j + 1]) {
                        minHealth[i][j] = 1;
                    } else {
                        minHealth[i][j] = minHealth[i][j + 1] - dungeon[i][j];
                    }
                } else if (i + 1 < m) {
                    if (dungeon[i][j] >= minHealth[i + 1][j]) {
                        minHealth[i][j] = 1;
                    } else {
                        minHealth[i][j] = minHealth[i + 1][j] - dungeon[i][j];
                    }
                } else {
                    if (dungeon[i][j] >= 1) {
                        minHealth[i][j] = 1;
                    } else {
                        minHealth[i][j] = 1 - dungeon[i][j];
                    }
                }
            }
        }

        return minHealth[0][0];
    }
};