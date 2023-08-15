//利用动态规划更新[2,6,10,6,8,3]这张矩形面积表
//brutal method
//O(n2)
//超出时间限制


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> beforeSmall(n, -1);
        vector<int> currentArea(n, 0);
        currentArea.at(0) = heights.at(0);
        int maxArea = heights.at(0);
        for (int i = 1; i < n; i++) {
            //找到最近的小于等于点
            int j = i - 1;
            while (j >= 0 && heights.at(j) > heights.at(i)) {
                //j--;
                j = beforeSmall.at(j);
            }

            if (j < 0) {
                currentArea.at(i) = heights.at(i) * (i + 1);
                if (currentArea.at(i) > maxArea) {
                    maxArea = currentArea.at(i);
                }
                beforeSmall.at(i) = -1;
                continue;
            }

            //沿高度递减链更新
            int jcopy = j;
            while (j >= 0) {
                currentArea.at(j) += heights.at(j);
                if (currentArea.at(j) > maxArea) {
                    maxArea = currentArea.at(j);
                }
                j = beforeSmall.at(j);
            }
            
            //更新新加入的点
            if (heights.at(i) > heights.at(jcopy)) {
                currentArea.at(i) = heights.at(i) * (i - jcopy);
                if (currentArea.at(i) > maxArea) {
                    maxArea = currentArea.at(i);
                }
                beforeSmall.at(i) = jcopy;
            } else {
                currentArea.at(i) = currentArea.at(jcopy);
                // if (currentArea.at(i) > maxArea) {
                //     maxArea = currentArea.at(i);
                // }
                beforeSmall.at(i) = beforeSmall.at(jcopy);
            }
        }


        return maxArea;
    }
};