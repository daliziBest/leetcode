//注意观察example1的output，能有所启发
//先排序

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result = {{}};
        sort(nums.begin(), nums.end());

        //core code
        int begin = 0;
        int end;
        while (begin < nums.size()) {
            //get begin and end of a new element
            end = begin + 1;
            while (end < nums.size()) {
                if (nums.at(end) == nums.at(begin)) {
                    end++;
                } else {
                    break;
                }
            }
            
            //insert
            int count = 1;
            int len = result.size();
            while (count <= end - begin) {          
                for (int i = 0; i < len; i++) {
                    vector<int> temp = result.at(i);
                    temp.insert(temp.end(), count, nums.at(begin));
                    result.push_back(temp);
                }

                count++;
            }

            begin = end; 
        }
        
        return result;
    }
};