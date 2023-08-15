//use auxiliary space

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> result;
        int i = 0;
        int j = 0;
        while (i < m && j < n) {
            if (nums1.at(i) <= nums2.at(j)) {
                result.push_back(nums1.at(i++));
            } else {
                result.push_back(nums2.at(j++));
            }
        }
        if (i < m) {
            while (i < m) {
                result.push_back(nums1.at(i++));
            }
        } else {
            while (j < n) {
                result.push_back(nums2.at(j++));
            }
        }

        nums1 = result;
    }
};