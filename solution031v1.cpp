//关键在于搞清楚next permutation如何获取
//先思考如何递归的按序生成所有的permutation
//接着从高位向低位移动，观察如何得到大的permutation，然后如何得到大的且更近的permutation
//最后观察得到如何获取next permutation
/**
从低位向高位遍历，检查当前位是否是已遍历数字是最大的，当遇到第一个不是最大的或者数组遍历完了，翻转(升序)其后数组，交换当前位与其后第一个超过自己的位，结束。
**/


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //从低位向高位遍历
        int i = nums.size() - 2;
        while (i >= 0) {
            if (nums.at(i) >= nums.at(i + 1)) {
                i--;
            } else {
                break;
            }
        }

        //翻转其后数组，升序排列
        int begin = i + 1;
        int end = nums.size() - 1;
        while (begin < end) {
            int temp = nums.at(begin);
            nums.at(begin) = nums.at(end);
            nums.at(end) = temp;
            begin++;
            end--;
        }

        //交换当前位
        if (i < 0) {
            return;
        }
        int j = i + 1;
        while (nums.at(j) <= nums.at(i)) {
            j++;
        }
        int temp = nums.at(i);
        nums.at(i) = nums.at(j);
        nums.at(j) = temp;
        return;
    }
};