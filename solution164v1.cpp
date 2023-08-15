//Pigeonhole Sort : https://www.geeksforgeeks.org/pigeonhole-sort/
//Counting sort : https://www.geeksforgeeks.org/counting-sort/  (only see basic part)
//geeksforgeeks.org/maximum-adjacent-difference-array-sorted-form/

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) {
            return 0;
        }

        vector<int> maxBucket(nums.size(), -1);
        vector<int> minBucket(nums.size(), -1);

        //calculate the min and the max value
        int MIN = nums[0];
        int MAX = nums[0];
        for (auto a : nums) {
            if (a < MIN) {
                MIN = a;
            }
            if (a > MAX) {
                MAX = a;
            }
        }
        if (MIN == MAX) {
            return 0;
        }

        //fill the bucket
        //bucket[0]和bucket[n - 1]一定有值
        for (int i = 0; i < nums.size(); i++) {
            int index = (nums.size() - 1) * (nums[i] - MIN) / (MAX - MIN);
            if (maxBucket[index] == -1) {
                maxBucket[index] = i;
            } else if (nums[maxBucket[index]] < nums[i]) {
                maxBucket[index] = i;
            }
            if (minBucket[index] == -1) {
                minBucket[index] = i;
            } else if (nums[minBucket[index]] > nums[i]) {
                minBucket[index] = i;
            }
        }

        //calculate the max interval
        int intervalLeft = nums[maxBucket[0]];
        int intervalRight;
        int result = -1;
        for (int i = 1; i < nums.size(); i++) {
            if (minBucket[i] != -1) {
                intervalRight = nums[minBucket[i]];
                result = intervalRight - intervalLeft > result ? intervalRight - intervalLeft : result;
                intervalLeft = nums[maxBucket[i]];
            }
        }

        return result;
    }
};