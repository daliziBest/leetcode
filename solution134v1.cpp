//用一个vector保存每段路程储油量和耗油量的差距
//从0开始向后顺时针检查，遇到储油量不够的情况，逆时针修正start gas station

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> gap;
        for (int i = 0; i < gas.size(); i++) {
            gap.push_back(gas[i] - cost[i]);
        }
        
        //注意end和start的初值
        int end = -1;
        int start = gas.size();
        int dif = 0;

    calEnd:
        while (++end < start) {
            dif += gap[end];
            if (dif < 0) {
                goto calStart;
            }
        }

        return start % gas.size();

    calStart:
        while (--start > end) {
            dif += gap[start];
            if (dif >= 0) {
                goto calEnd; 
            }
        }

        return -1;

    }
};