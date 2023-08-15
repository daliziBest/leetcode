//v1沿高度递减链更新耗时过多
//对v1进行修改
//不逐步更新currentArea, 构建beforeSmall之后直接计算最终的currentArea

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> beforeSmall(n, -1);
        vector<int> AfterSmall(n, n);
        //vector<int> everyArea(n, 0);
        int maxArea = -1;
        
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