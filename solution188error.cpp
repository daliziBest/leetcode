//又来幺蛾子
//recursion : https://takeuforward.org/data-structure/buy-and-sell-stock-iv-dp-38/
//耗时超出限制

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int maxPro = 0;
        myMaxProfit(prices, 0, 0, k, 0, maxPro);

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
            myMaxProfit(prices, start + 1, 1, remainK, currentPro - prices[start], maxPro);
        } else {
            myMaxProfit(prices, start + 1, 0, remainK - 1, currentPro + prices[start], maxPro);
        }
    }
};