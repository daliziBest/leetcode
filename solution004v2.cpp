class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //corner case
        if (nums1.size() == 0) {
            return findMedianMergedArray(nums2);
        }
        if (nums2.size() == 0) {
            return findMedianMergedArray(nums1);
        }
        
        //思路:让两个index跑的快一点，跑到刚好下一个要merge的数是我们的目标数的位置
        vector<int>& smallerArray = nums1.size() <= nums2.size() ? nums1 : nums2;
        vector<int>& largerArray = nums1.size() <= nums2.size() ? nums2 : nums1;
        
        //range 0~size()
        int indexSmall;
        int indexLarge;
        const int goalnums = (smallerArray.size() + largerArray.size() - 1) / 2;

        //core code
        //binary search
        int start = 0;
        int end = smallerArray.size();
        while (true) {
            indexSmall = (start + end) / 2;
            indexLarge = goalnums - indexSmall;

            //check
            //move left
            if (indexLarge < 0) {
                end = indexSmall - 1;
                continue;
            }
            //move right
            if (indexLarge > largerArray.size()) {
                start = indexSmall + 1;
                continue;
            }

            //smallLeft:indexSmall - 1         smallRight:indexSmall
            //largeLeft:indexLarge - 1         largeRight:indexLarge
            /** 
                we want smallLeft <= largeRight
                        largeLeft < smallRight
            **/
            //if smallLeft > largeRight, move left
            //if largeLeft >= smallRight, move right
            if (indexSmall - 1 >= 0 && indexLarge < largerArray.size() && smallerArray.at(indexSmall - 1) > largerArray.at(indexLarge)) {
                end = indexSmall - 1;
            }else if (indexLarge - 1 >= 0 && indexSmall < smallerArray.size() && largerArray.at(indexLarge - 1) >= smallerArray.at(indexSmall)) {
                start = indexSmall + 1;
            }else {
                break;
            }
        }



        //拿到index，接着merge取出目标数
        //if total length is even
        if ((smallerArray.size() + largerArray.size()) % 2 == 0) {
            double sum = getnext(smallerArray, largerArray, indexSmall, indexLarge);
            sum += getnext(smallerArray, largerArray, indexSmall, indexLarge);
            return sum / 2;
        }else {
            return getnext(smallerArray, largerArray, indexSmall, indexLarge);
        }
    }
private:
    double findMedianMergedArray(vector<int>& merged) {
        int length = merged.size();
        bool isEven = length % 2 == 0;

        //if length is odd
        if (!isEven) {
            return merged.at(length / 2);
        }else {
            return ((double)merged.at(length / 2 - 1) + merged.at(length / 2)) / 2; 
        }
    }
    //assume that index is valid
    int getnext(vector<int>& nums1, vector<int>& nums2, int& index1, int& index2) {
        if (index1 == nums1.size()) {
            return nums2.at(index2++);
        }
        if (index2 == nums2.size()) {
            return nums1.at(index1++);
        }
        if (nums1.at(index1) <= nums2.at(index2)) {
            return nums1.at(index1++);
        }else {
            return nums2.at(index2++);
        }
    }
};