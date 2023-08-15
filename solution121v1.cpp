//借助一个额外空间,统计在每个点卖掉的最大收益

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> maxProfitEvery = {0};
        int minBefore = prices.at(0);
        for (int i = 1; i < prices.size(); i++) {
            if (minBefore < prices.at(i)) {
                maxProfitEvery.push_back(prices.at(i) - minBefore);
            } else {
                maxProfitEvery.push_back(0);
            }
            if (prices.at(i) < minBefore) {
                minBefore = prices.at(i);
            }
        }


        int result = 0;
        for (auto a : maxProfitEvery) {
            if (a > result) {
                result = a;
            }
        }
        return result;
    }
};