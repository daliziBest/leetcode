//从最简单的回文串验证方法进行改进
// 要么修改字符串s，要么修改遍历过程

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;
        while (i < j)
        {
            if (!isrange(s[i]))
            {
                i++;
                continue;
            }
            if (!isrange(s[j]))
            {
                j--;
                continue;
            }
            char i1 = ('A' <= s[i] && s[i] <= 'Z') ? s[i] + ('a' - 'A') : s[i];
            char j1 = ('A' <= s[j] && s[j] <= 'Z') ? s[j] + ('a' - 'A') : s[j];
            if (i1 == j1)
            {
                i++;
                j--;
            }
            else
            {
                return false;
            }
        }

        return true;
    }
private:
    bool isrange(char c)
    {
        if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || ('0' <= c && c <= '9'))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};