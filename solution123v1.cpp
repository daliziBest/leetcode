//类似121
//使用两个额外空间，一个统计到第i天能获得的最大收益，另一个统计从第i天能获的最大收益

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> maxTo(prices.size(), 0);
        vector<int> maxFrom(prices.size(), 0);
        
        int max = 0;
        int temp;
        int minBefore = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            temp = prices[i] > minBefore ? prices[i] - minBefore : 0;
            max = temp > max ? temp : max;
            maxTo[i] = max;
            minBefore = prices[i] < minBefore ? prices[i] : minBefore;
        }

        max = 0;
        int maxAfter = prices.back();
        for (int i = prices.size() - 2; i >= 0; i--) {
            temp = prices[i] < maxAfter ? maxAfter - prices[i] : 0;
            max = temp > max ? temp : max;
            maxFrom[i] = max;
            maxAfter = prices[i] > maxAfter ? prices[i] : maxAfter;
        }

        int result = 0;
        for (int i = 0; i < prices.size() - 1; i++) {
            result = maxTo[i] + maxFrom[i + 1] > result ? maxTo[i] + maxFrom[i + 1] : result;
        }
        result = maxTo.back() > result ? maxTo.back() : result;
        return result;
    }
};