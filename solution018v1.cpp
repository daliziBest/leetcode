//3sum问题增强版
//把4sum问题转化为2sum问题
//two pointer
//O(n3)
//小心int的overflow

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        
        //core code
        //i,j,k,l
        for (int i = 0; i < nums.size(); ) {
            for (int j = i + 1; j < nums.size(); ) {
                int k = j + 1;
                int l = nums.size() - 1;
                //根据题目给定的输入数值范围，此处使用int会造成overflow
                //const int T = target - nums.at(i) - nums.at(j);
                const long T = (long)target - nums.at(i) - nums.at(j);
                while (k < l) {
                    if (nums.at(k) + nums.at(l) == T) {
                        result.push_back({nums.at(i), nums.at(j), nums.at(k), nums.at(l)});
                        do {
                            k++;
                        } while (k < nums.size() && nums.at(k) == nums.at(k - 1));
                        do {
                            l--;
                        } while (l >= 0 && nums.at(l) == nums.at(l + 1));
                    } else if (nums.at(k) + nums.at(l) > T) {
                        l--;
                    } else {
                        k++;
                    }
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