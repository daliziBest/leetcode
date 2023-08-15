//在v3基础上用二分查找加快merge速度, 参考035的二分插入

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        //[start, end) denote that all the node is merged
        //find start, and determine the start of newInterval
        int start = biFind(intervals, 0, newInterval.at(0));
        if (start - 1 >= 0 && newInterval.at(0) <= intervals[start - 1][1]) {
            newInterval[0] = intervals[start - 1][0];
            start--;
        } else {
            //什么都不用做
        }
        //find end, and determine the end of newInterval
        int end = biFind(intervals, 1, newInterval.at(1));
        if (end < intervals.size() && newInterval.at(1) >= intervals[end][0]) {
            newInterval[1] = intervals[end][1];
            end++;
        } else {
            //什么都不用做
        }
        
        //insert intervals before start
        for (int i = 0; i < start; i++) {
            result.push_back(intervals.at(i));
        }
        //insert newInterval
        result.push_back(newInterval);
        //insert intervals after end
        for (int i = end; i < intervals.size(); i++) {
            result.push_back(intervals.at(i));
        }

        return result;
    }

private:
    //找到num，返回索引，如果没有找到num，返回num位于的区间或者应该插入的位置
    //a[i-1]<num<=a[i]
    //intervals可以为空
    int biFind(vector<vector<int>>& intervals, int index, int num) {
        int begin = 0;
        int end = intervals.size() - 1;
        int mid;
        while (begin <= end) {
            mid = (begin + end) / 2;
            if (intervals[mid][index] == num) {
                return mid;
            } else if (intervals[mid][index] < num) {
                begin = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return begin;
    }
};