//055的改进版
//在055解法上改进
//只需对055找到的路径依次merge(借助一个额外数组表示跳跃路径)
//why it is right???
//Because the path of the minimum number jumps:首先，找到最远能一下跳到终点的点A，接着再余下点找到最远能跳到点A的点B，再接着......
//O(n)

class Solution {
public:
    int jump(vector<int>& nums) {
        //corner case
        if (nums.size() == 1) {
            return 0;
        }

        int result = 0;
        vector<int> path(nums.size(), -1);
        
        //core code
        int togo = nums.size() - 1;
        int i = nums.size() - 2;
        while (i >= 0) {
            if (i + nums.at(i) >= togo) {
                //merge and update result
                result++;
                while (togo != nums.size() - 1) {
                    if (i + nums.at(i) >= path.at(togo)) {
                        togo = path.at(togo);
                        result--;
                    } else {
                        break;
                    }
                }
                path.at(i) = togo;

                togo = i;
                i--;
            } else {
                i--;
            }
        }        

        return result;
    }
};