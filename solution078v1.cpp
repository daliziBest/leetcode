//可以不使用递归

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result = {{}};
        for (int a : nums) {
            int len = result.size();
            for (int i = 0; i < len; i++) {
                vector<int> temp = result.at(i);
                temp.push_back(a);
                result.push_back(temp);
            }
        }
        
        return result;
    }
};