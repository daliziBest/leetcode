//改进v1，不需要借助额外空间

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minBefore = prices.at(0);
        int result = 0;
        for (int i = 1; i < prices.size(); i++) {
            int temp = prices.at(i) > minBefore ? prices.at(i) - minBefore : 0;
            result = temp > result ? temp : result;
            minBefore = prices.at(i) < minBefore ? prices.at(i) : minBefore;
        }

        return result;
    }
};