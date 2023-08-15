//从所有组合中找出符合条件的所有组合
//等同于用一些面额找零
//recursion+backtracking


class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        //先排序
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> result;
        vector<int> currentCom;
        int start = 0;
        myCombination(candidates, start, target, result, currentCom);

        return result;
    }
private:
    void myCombination(vector<int>& candidates, int start, int target, vector<vector<int>>& result, vector<int>& currentCom) {
        //base case
        if (start >= candidates.size()) {
            return;
        }
        if (target < candidates.at(start)) {
            return;
        }

        //core code
        //case1
        int newTarget = target - candidates.at(start);
        if (newTarget == 0) {
            currentCom.push_back(candidates.at(start));
            result.push_back(currentCom);
            currentCom.pop_back();
            return;
        } else {
            currentCom.push_back(candidates.at(start));
            myCombination(candidates, start, newTarget, result, currentCom);
            currentCom.pop_back();
        }

        //case2
        myCombination(candidates, start + 1, target, result, currentCom);
    }
};