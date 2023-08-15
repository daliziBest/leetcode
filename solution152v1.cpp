//1如果nums无0
//2如果nums有0,将nums分割成一段一段无0的，转1

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> zeroIndex;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                zeroIndex.push_back(i);
            }
        }

        if (zeroIndex.empty()) {
            return myMaxProduct(nums, 0, nums.size() - 1);
        }

        int result = 0;
        int temp;
        if (zeroIndex[0] > 0) {
            temp = myMaxProduct(nums, 0, zeroIndex[0] - 1);
            result = temp > result? temp : result;
        }
        for (int i = 1; i < zeroIndex.size(); i++) {
            if (zeroIndex[i] - zeroIndex[i - 1] > 1) {
                temp = myMaxProduct(nums, zeroIndex[i - 1] + 1, zeroIndex[i] - 1);
                result = temp > result ? temp : result;
            }
        }
        if (zeroIndex.back() < nums.size() - 1) {
            temp = myMaxProduct(nums, zeroIndex.back() + 1, nums.size() - 1);
            result = temp > result ? temp : result;
        }

        return result;
    }

private:
    //[start,end]不包含0
    int myMaxProduct(vector<int>& nums, int start, int end) {
        // if (start == end) {
        //     return nums[start];
        // }

        int result = 1;
        for (int i = start; i <= end; i++) {
            result *= nums[i];
        }
        if (result > 0) {
            return result;
        }

        int negleft = start;
        while (true) {
            if (nums[negleft] > 0) {
                negleft++;
            } else {
                break;
            }
        }
        if (negleft < end) {
            int temp = 1;
            for (int i = negleft + 1; i <= end; i++) {
                temp *= nums[i];
            }
            result = temp > result ? temp : result;
        }

        int negright = end;
        while (true) {
            if (nums[negright] > 0) {
                negright--;
            } else {
                break;
            }
        }
        if (negright > start) {
            int temp = 1;
            for (int i = start; i <= negright - 1; i++) {
                temp *= nums[i];
            }
            result = temp > result ? temp : result;
        }

        return result;
    }
};