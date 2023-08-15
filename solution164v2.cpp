//Pigeonhole Sort : https://www.geeksforgeeks.org/pigeonhole-sort/
//Counting sort : https://www.geeksforgeeks.org/counting-sort/  (only see basic part)
//geeksforgeeks.org/maximum-adjacent-difference-array-sorted-form/
//bucket不存储索引，直接存储值，可略微加快一点速度

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
                maxBucket[index] = nums[i];
            } else if (maxBucket[index] < nums[i]) {
                maxBucket[index] = nums[i];
            }
            if (minBucket[index] == -1) {
                minBucket[index] = nums[i];
            } else if (minBucket[index] > nums[i]) {
                minBucket[index] = nums[i];
            }
        }

        //calculate the max interval
        int intervalLeft = maxBucket[0];
        int intervalRight;
        int result = -1;
        for (int i = 1; i < nums.size(); i++) {
            if (minBucket[i] != -1) {
                intervalRight = minBucket[i];
                result = intervalRight - intervalLeft > result ? intervalRight - intervalLeft : result;
                intervalLeft = maxBucket[i];
            }
        }

        return result;
    }
};