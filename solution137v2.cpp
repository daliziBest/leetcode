//在v1基础上，想办法对所有二进制位同时处理
//用a和b两个状态位组合表示添加新x后对3取余的变化，00表示0,01表示1,10表示2
//x=0,位组合不变，x=1，位组合按照00——>01——>10循环变化
//列出真值表(需要确定输入输出)，根据真值表写出逻辑表达式
//https://blog.csdn.net/Galaxy_wzs/article/details/80545160

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //初始状态位
        int a = 0;
        int b = 0;
        
        int anew;
        int bnew;
        for (auto x : nums) {
            anew = ~x & a & ~b | x & ~a & b;
            bnew = ~a & (x ^ b);
            a = anew;
            b = bnew;
        }

        return a | b;
    }
};