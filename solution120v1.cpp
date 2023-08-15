//动态规划

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> minSum = {triangle[0][0]};
        vector<int> temp;
        for (int i = 1; i < triangle.size(); i++) {
            temp = minSum;
            minSum.clear();
            for (int j = 0; j <= i; j++) {
                if (j == 0) {
                    minSum.push_back(triangle[i][j] + temp[0]);
                } else if (j == i) {
                    minSum.push_back(triangle[i][j] + temp[j - 1]);
                } else {
                    int smaller = temp[j - 1] < temp[j] ? temp[j - 1] : temp[j];
                    minSum.push_back(triangle[i][j] + smaller);
                }
            }
        }
        
        int result = 3000000;
        for (auto a : minSum) {
            if (a < result) {
                result = a;
            }
        }

        return result;
    }
};