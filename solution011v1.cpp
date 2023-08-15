//双指针
//注意water area随着搜索空间的变化规律,可用二维搜索空间辅助理解
//然后根据每次搜索结果削减搜索空间，减少搜索次数

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        int start = 0;
        int end = height.size() - 1;

        while (start < end) {
            int current = (end - start) * min(height.at(start), height.at(end));
            max = current > max ? current : max;

            if (height.at(start) < height.at(end)) {
                start++;
            }else if (height.at(end) < height.at(start)) {
                end--;
            }else {
                start++;
                end--;
            }
        }

        return max;
    }
};