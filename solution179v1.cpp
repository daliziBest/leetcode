//leetcode.cn/problems/largest-number/solution/zui-da-shu-by-leetcode-solution-sid5/
//公式化证明(有时候单靠图形不管用)
//这题很难
//C++自定义排序
//https://cplusplus.com/reference/algorithm/sort/
//https://en.cppreference.com/w/cpp/algorithm/sort

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
        string abString = to_string(a) + to_string(b);
        string baString = to_string(b) + to_string(a);
        long long int ab = stoll(abString);
        long long int ba = stoll(baString);
        if (ab > ba) {
            return true;
        } else {
            return false;
        }
    }
};