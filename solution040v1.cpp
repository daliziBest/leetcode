//从所有组合中找出符合条件的所有组合
//等同于用一些硬币找零
//recursion + backtracking
//对039解法稍微改动即可

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        //排序
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> result;
        vector<int> currentCom;
        int start = 0;
        myCombinationSum2(candidates, start, target, result, currentCom);

        return result;
    }
private:
    void myCombinationSum2(vector<int>& candidates, int start, int target, vector<vector<int>>& result, vector<int>& currentCom) {
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
            myCombinationSum2(candidates, start + 1, newTarget, result, currentCom);
            currentCom.pop_back();
        }

        //case2
        //find next search location
        int i;
        for (i = start + 1; i < candidates.size(); i++) {
            if (candidates.at(i) != candidates.at(i - 1)) {
                break;
            }
        }
        myCombinationSum2(candidates, i, target, result, currentCom);
    }
};