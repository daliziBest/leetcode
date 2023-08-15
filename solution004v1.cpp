//brutal method with an auxiliary array
//m or n maybe equals 0!

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
        
        vector<int> mergedArray;
        auto index1 = nums1.cbegin();
        auto index2 = nums2.cbegin();
        while (index1 != nums1.cend() && index2 != nums2.cend()) {
            if (*index1 <= *index2) {
                mergedArray.push_back(*index1);
                index1++;
            }else {
                mergedArray.push_back(*index2);
                index2++;
            }
        }
        if (index1 == nums1.cend()) {
            for ( ; index2 != nums2.cend(); index2++) {
                mergedArray.push_back(*index2);
            }
        }else {
            for ( ; index1 != nums1.cend(); index1++) {
                mergedArray.push_back(*index1);
            }
        }

        return findMedianMergedArray(mergedArray);
        
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
};