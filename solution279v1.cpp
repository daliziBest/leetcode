//有点难
//N(logN)
class Solution {
public:
    int numSquares(int n) {
        vector<int> mincountvec;
        mincountvec.push_back(0);
        int i = 1;
        while (i <= n)
        {
            //计算和为i的完全平方数的最少数量 
            int j = floor(sqrt(i));
            int mincount = i;
            while (j >= 1)
            {
                mincount = mincountvec[i - j * j] + 1 < mincount ? mincountvec[i - j * j] + 1 : mincount;
                j--;
            }
            mincountvec.push_back(mincount);
            i++;
        }
        return mincountvec.back();
    }
};