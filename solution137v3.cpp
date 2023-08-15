//在v1基础上，想办法对所有二进制位同时处理
//用a和b两个状态位组合表示添加新x后对3取余的变化，00表示0,01表示1,10表示2
//x=0,位组合不变，x=1，位组合按照00——>01——>10循环变化
//列出真值表(需要确定输入输出)，根据真值表写出逻辑表达式
//v2里新a和b都需要旧a和b算出，因此不能立马赋值，需要缓存新的a和b，这里将其改进，先算新b再借助新b算新a(借助新的真值表)，可以省去缓存变量
//不过貌似异或的运算相比与非或都费时一些

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0;
        int b = 0;

        for (auto x : nums) {
            b = ~a & (x ^ b);
            a = ~b & (x ^ a);
        }

        return a | b;
    }
};