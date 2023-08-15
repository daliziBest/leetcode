//046增加了约束
//先排序, 思想类似有重复数的组合问题
//用FIFO队列处理

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        vector<int> current;
        queue<int> remains;
        for (int i : nums) {
            remains.push(i);
        }

        myPermuteUnique(remains, result, current);

        return result;
    }
    
private:
    void myPermuteUnique(queue<int>& remains, vector<vector<int>>& result, vector<int>& current) {
        //base case
        if (remains.size() == 1) {
            current.push_back(remains.front());
            result.push_back(current);
            current.pop_back();
            return;
        }

        //core code
        int i = 0;
        int temp;
        do {
            i++;
            if (i > 1 && remains.front() == remains.back()) {
                temp = remains.front();
                remains.pop();
                remains.push(temp);
                continue;
            }
            temp = remains.front();
            current.push_back(temp);
            remains.pop();

            myPermuteUnique(remains, result, current);

            current.pop_back();
            remains.push(temp);
        } while (i < remains.size());
    }
};