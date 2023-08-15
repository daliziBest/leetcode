//关键如何把剩下的元素传递到iteration function中
//也可使用set来传递剩余元素
//注意set的erase和insert操作后iterator是否validated!!!
//用iterator迭代set是有序的，迭代hashset是无序的!!!

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        //unordered_set<int> remains(nums.cbegin(), nums.cend());
        set<int> remains(nums.cbegin(), nums.cend());

        myPermute(remains, result, current);
        
        return result;
    }
    
private:
    //使用set来传递剩余元素
    void myPermute(set<int>& remains, vector<vector<int>>& result, vector<int>& current) {
        //base case
        if (remains.size() == 0) {
            result.push_back(current);
            return;
        }

        //core code
        //此处不能使用unordered_set,因为unordered_set是无序遍历,会陷入无限循环!!!
        for (auto i = remains.cbegin(); i != remains.cend(); i++) {
            int temp = *i;
            current.push_back(temp);

            //从set中删除选中元素,此时迭代器i失效,erase本身返回的iterator在myPermute()结束后也会失效!!
            remains.erase(i);

            myPermute(remains, result, current);

            current.pop_back();
            i = remains.insert(temp).first;
        }
    }
};