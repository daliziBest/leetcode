//又来幺蛾子
//recursion : https://takeuforward.org/data-structure/buy-and-sell-stock-iv-dp-38/
//递归耗时太多
//想办法缩减一点问题规模
//依旧超出时间限制

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<int> minAndMax;
        int i = 0;
        while (true) {
            while (i < prices.size() - 1 && prices[i] >= prices[i + 1]) {
                i++;
            }
            if (i == prices.size() - 1) {
                break;
            }
            minAndMax.push_back(prices[i++]);
            while (i < prices.size() - 1 && prices[i] <= prices[i + 1]) {
                i++;
            }
            if (i == prices.size() - 1) {
                minAndMax.push_back(prices.back());
                break;
            }
            minAndMax.push_back(prices[i++]);
        }
        
        int maxPro = 0;
        myMaxProfit(minAndMax, 0, 0, k, 0, maxPro);
        return maxPro;
    }

private:
    void myMaxProfit(vector<int>& prices, int start, int buyOrSell, int remainK, int currentPro, int& maxPro) {
        //base case
        if (remainK == 0 || start >= prices.size()) {
            maxPro = currentPro > maxPro ? currentPro : maxPro;
            return;
        }

        //no deal
        myMaxProfit(prices, start + 1, buyOrSell, remainK, currentPro, maxPro);
        //one transaction
        if (buyOrSell == 0) {
            if (start % 2 == 0) {
                myMaxProfit(prices, start + 1, 1, remainK, currentPro - prices[start], maxPro);
            }
        } else {
            if (start % 2 == 1) {
                myMaxProfit(prices, start + 1, 0, remainK - 1, currentPro + prices[start], maxPro);
            }
        }
    }
};