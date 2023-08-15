//逐个二进制位判断，将所有数的第i位累加起来对3取余，得到目标数的第i位

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        int temp;
        for (int i = 0; i < sizeof(int) * 8; i++) {
            temp = 0;
            for (auto a : nums) {
                temp += a >> i & 1;
            }
            temp = temp % 3;
            result = temp << i | result;
        }

        return result;
    }
};