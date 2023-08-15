//https://iq.opengenus.org/maximal-rectangle-problem/
//和084放在一起看, 注意思路的变化, 有点动态规划的味道
//如何获取添加一行后所增加的所有矩形?
//注意matrix里的元素是char，不是int

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix[0].size();
        int m = matrix.size();
        vector<int> histogram(n, 0);
        int maxArea = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                //if (matrix[i][j] == 0)    //error!
                if (matrix[i][j] == '0') {
                    histogram.at(j) = 0;
                } else {
                    histogram.at(j) += 1;
                }
            }

            int temp = largestRectangleArea(histogram);
            if (temp > maxArea) {
                maxArea = temp;
            }
        }
        
        return maxArea;
    }

private:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> beforeSmall(n, -1);
        vector<int> AfterSmall(n, n);
        //vector<int> everyArea(n, 0);
        int maxArea = 0;
        
        //computer beforeSmall
        for (int i = 1; i < n; i++) {
            int j = i - 1;
            while(j >=0 && heights.at(j) >= heights.at(i)) {
                j = beforeSmall.at(j);
            }
            // if (j < 0) {
            //     beforeSmall.at(i) = -1;
            // } else {
            //     beforeSmall.at(i) = j;
            // }
            beforeSmall.at(i) = j;
        }

        //computer AfterSmall
        for (int i = n - 2; i >= 0; i--) {
            int j = i + 1;
            while (j < n && heights.at(j) >= heights.at(i)) {
                j = AfterSmall.at(j);
            }
            // if (j < n) {
            //     AfterSmall.at(i) = j;
            // } else {
            //     AfterSmall.at(i) = n;
            // }
            AfterSmall.at(i) = j;
        }

        //computer everyArea
        for (int i = 0; i < n; i++) {
            int temp = heights.at(i) * (AfterSmall.at(i) - beforeSmall.at(i) - 1);
            if (temp > maxArea) {
                maxArea = temp;
            }
        }

        return maxArea;
    }
};