//https://fizzbuzzed.com/top-interview-questions-1/
/**
难点：
1.Ensuring no duplicate outputs!!!!!!!!!
2.Creating the O(n2) solution that the interviewers expect (instead of the O(n3) straightforward solution).
**/

//brutal method O(n3)
//this code only solve 1
//遍历的时候就跳过那些拥有相同组合的三元组
//对原数组进行排序，在排序后的数组上遍历
//借助数组的histogram方便理解
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        //遍历
        //一个index遍历完成后，跳入下个补集当中，不再是index++
        for (int i = 0; i < nums.size(); ) {
            for (int j = i + 1; j < nums.size(); ) {
                for (int k = j + 1; k < nums.size(); ) {
                    if (nums.at(i) + nums.at(j) + nums.at(k) == 0) {
                        result.push_back({nums.at(i), nums.at(j), nums.at(k)});
                    }

                    do {
                        k++;
                    } while (k < nums.size() && nums.at(k) == nums.at(k - 1));
                }

                do {
                    j++;
                } while (j < nums.size() && nums.at(j) == nums.at(j - 1));
            }

            do {
                i++;
            } while (i < nums.size() && nums.at(i) == nums.at(i - 1));
        }

        return result;
    }
};