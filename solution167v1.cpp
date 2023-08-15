//N2 -> NlogN -> ?
//对binary search进行修改
//(logN)^2

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int index1 = 0;
        int num2 = target - numbers[index1];
        
        int start = 1;
        int end = numbers.size() - 1;
        int index2;
        bool isFindNum2 = binarySearch(numbers, start, end, num2, index2);
        while (!isFindNum2) {
            while (numbers[++index1] == numbers[index1 - 1]) {

            }
            num2 = target - numbers[index1];
            start = index1 + 1;
            end = index2 - 1;
            isFindNum2 = binarySearch(numbers, start, end, num2, index2);
        }

        return {index1 + 1, index2 + 1};
    }

private:
    //calculate target location, index2 range is [start, end + 1]
    bool binarySearch(vector<int>& numbers, int start, int end, int target, int& index2) {
        int mid;
        while (start <= end) {
            mid = (start + end) / 2;
            if (numbers[mid] == target) {
                index2 = mid;
                return true;
            } else if (numbers[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        index2 = start;
        return false;
    }
};