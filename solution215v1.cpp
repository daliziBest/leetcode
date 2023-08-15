//partition
//耗时较多，partition没有加入随机性

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() - k;

        int start = 0;
        int end = nums.size() - 1;
        int temp = partition(nums, start, end);
        while (temp != k) {
            if (temp < k) {
                start = temp + 1;
                temp = partition(nums, start, end);
            } else {
                end = temp - 1;
                temp = partition(nums, start, end);
            }
        }

        return nums[temp];
    }

private:
    //总用第一个数切分
    int partition(vector<int>& nums, int start, int end) {
        int pivot = nums[start];
    
    toLeft:
        while (end != start) {
            if (nums[end] >= pivot) {
                end--;
            } else {
                nums[start++] = nums[end];
                goto toRight;
            }
        }
        nums[start] = pivot;
        return start;

    toRight:
        while (start != end) {
            if (nums[start] <= pivot) {
                start++;
            } else {
                nums[end--] = nums[start];
                goto toLeft; 
            }
        }
        nums[end] = pivot;
        return end;
    }
};