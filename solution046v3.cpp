//关键如何组织剩余元素并传递
//也可以使用FIFO队列

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        queue<int> remains;
        //以下两种初始化都没发用!
        //queue<int> remains(nums);     //until C++11
        //queue<int> remains(nums.cbegin(), nums.cend());   //since C++23
        for (int a : nums) {
            remains.push(a);
        }

        myPermute(remains, result, current);

        return result;
    }
    
private:
    void myPermute(queue<int>& remains, vector<vector<int>>& result, vector<int> current) {
        //base case
        if (remains.size() == 1) {
            current.push_back(remains.front());
            result.push_back(current);
            current.pop_back();
            return;
        }

        //core code
        //start用于检测是否遍历完所有元素
        int start = remains.front();
        do {
            int temp = remains.front();
            current.push_back(temp);
            remains.pop();
            
            myPermute(remains, result, current);

            current.pop_back();
            remains.push(temp);
        } while (remains.front() != start);
    }
};