//对intervals排序可以加快处理速度
//如何传递函数？comp不能作为private
//comp里的<不能换成<=!!!!!
//A sequence is sorted with respect to a comparator comp if for any iterator it pointing to the sequence and any non-negative integer n such that it + n is a valid iterator pointing to an element of the sequence, comp(*(it + n), *it) (or *(it + n) < *it) evaluates to false.


bool comp(vector<int>& a, vector<int>& b) {
    //<不能换成<=
    return a.at(0) < b.at(0);
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        vector<vector<int>> result;
        
        //all intervals is processed through temp
        vector<int> temp = intervals.at(0);
        for (int i = 1; i < intervals.size(); i++) {
            if (temp.at(1) < intervals[i][0]) {
                result.push_back(temp);
                temp = intervals.at(i);
            } else {
                temp.at(1) = temp.at(1) >= intervals[i][1] ? temp.at(1) : intervals[i][1];
            }
        }
        result.push_back(temp);

        return result;
    }
};