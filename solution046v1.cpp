//关键如何把剩下的元素传递到iteration function中
//可以构造新vector来传递
//涉及vector的range constructor和range 
//效率较低

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        myPermute(nums, result, current);
        
        return result;
    }
    
private:
    //构造新vector来传递剩余元素
    void myPermute(vector<int>& nums, vector<vector<int>>& result, vector<int>& current) {
        //base case
        if (nums.size() == 1) {
            current.push_back(nums.at(0));
            result.push_back(current);
            current.pop_back();
            return;
        }

        //core code
        for (auto i = nums.cbegin(); i != nums.cend(); i++) {
            current.push_back(*i);

            //将剩余元素放入另一个vector中
            vector<int> remains(nums.cbegin(), i);
            remains.insert(remains.cend(), i + 1, nums.cend());

            myPermute(remains, result, current);

            current.pop_back();
        }
    }
};