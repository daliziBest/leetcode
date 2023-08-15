//partition
//v1效率不高，所以v2在切分时添加一点随机性
//但v2我设计的随机并不完美，因为随机到end处的概率较低
//这里使用官方c++提供的随机方法

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
        //随机挑选一个数，交换到首位
        random_device r;
        default_random_engine e1(r());
        uniform_int_distribution<int> uniform_dist(start, end);
        int exchange = uniform_dist(e1);

        int temp = nums[start];
        nums[start] = nums[exchange];
        nums[exchange] = temp;


        //使用首位元素切分
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