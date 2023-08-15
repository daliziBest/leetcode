//3sum问题的改进版
//two pointer
//O(n2)

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result;
        int currentDif = INT_MAX;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); i++) {
            //two pointer
            int j = i + 1;
            int k = nums.size() - 1;
            const int T = target - nums.at(i);
            while (j < k) {
                //update if current is better
                int sumJandK = nums.at(j) + nums.at(k);
                if(abs(sumJandK - T) < currentDif) {
                    result = nums.at(i) + sumJandK;
                    currentDif = abs(sumJandK - T);
                }
                //move
                if (sumJandK == T) {
                    return result;
                } else if (sumJandK < T) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        

        return result;
    }
};