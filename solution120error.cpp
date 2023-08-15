//递归回溯遍历所有组合
//超出时间限制

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> current;
        int result = 3000000;
        myMinimumTotal(triangle, 0, 0, current, result);

        return result;
    }

private:
    void myMinimumTotal(vector<vector<int>>& triangle, int i, int j, vector<int>& current, int& result) {
        //base case
        if (i == triangle.size() - 1) {
            current.push_back(triangle[i][j]);
            int sum = 0;
            for (auto a : current) {
                sum += a;
            }
            if (sum < result) {
                result = sum;
            }
            current.pop_back();
            return;
        }

        current.push_back(triangle[i][j]);
        myMinimumTotal(triangle, i + 1, j, current, result);
        myMinimumTotal(triangle, i + 1, j + 1, current, result);
        current.pop_back();

        return;
    }
};