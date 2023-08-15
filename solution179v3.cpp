//leetcode.cn/problems/largest-number/solution/zui-da-shu-by-leetcode-solution-sid5/
//公式化证明(有时候单靠图形不管用)
//这题很难
//C++自定义排序
//https://cplusplus.com/reference/algorithm/sort/
//https://en.cppreference.com/w/cpp/algorithm/sort
//可以再改进一下，先字典序，当出现前缀一致时再使用新排序

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), compare);
        string result = "";
        for (auto a : nums) {
            result += to_string(a);
        }

        if (result[0] == '0') {
            return "0";
        }
        return result;
    }

private:
    //sort要求比较函数需要是static类型
    //strict weak ordering
    static bool compare(int a, int b) {
        string aString = to_string(a);
        string bString = to_string(b);
        int len = aString.size() < bString.size() ? aString.size() : bString.size();
        for (int i = 0; i < len; i++) {
            if (aString[i] > bString[i]) {
                return true;
            } else if (aString[i] < bString[i]) {
                return false;
            }
        }
        
        if (aString.size() == bString.size()) {
            return false;
        }

        string abString = aString + bString;
        string baString = bString + aString;
        long long int ab = stoll(abString);
        long long int ba = stoll(baString);
        if (ab > ba) {
            return true;
        } else {
            return false;
        }
        // string abString = aString + bString;
        // string baString = bString + aString;
        // if (abString > baString) {
        //     return true;
        // } else {
        //     return false;
        // }
    }
};