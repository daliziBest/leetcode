//partition
//v1效率不高，v2在切分时添加一点随机性
//我设计的随机并不完美，因为随机到end处的概率较低

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
    //随机挑选一个数，交换到首位进行切分
    int partition(vector<int>& nums, int start, int end) {
        double ratio = (double)rand() / RAND_MAX;
        int exchange = start + (end - start) * ratio;
        int temp = nums[start];
        nums[start] = nums[exchange];
        nums[exchange] = temp;

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