//所有的严格递增区间
//可以用DP规范去写

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i - 1] < prices[i]) {
                result += prices[i] - prices[i - 1];
            }
        }

        return result;
    }
};