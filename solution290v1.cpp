//熟悉string类和unordered_map类的使用
//将模式转换成统一形式再比较

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int num = pattern.size();
        //vector<int> pattern_inmath, s_inmath;
        unordered_map<char, int> pattern_map;
        unordered_map<string, int> s_map;
        string temp;    //保存从s每一次提取的word
        int counter1 = 0;   //用于hash的value
        int counter2 = 0; 
        int x,y;   //用于比较模式是否相同
        int index_s = 0;  //用于指示s里下一个单词的起始位置
        for (int i = 0; i < num; i++)
        {
            
            // if ((auto iter = pattern_map.find(pattern[i])) == pattern_map.end()) //没找到
            auto iter1 = pattern_map.find(pattern[i]);
            if (iter1 == pattern_map.end())      //没找到
            {
                x = counter1;
                pattern_map.insert({pattern[i], counter1++});
                // pattern_map[pattern[i]] = counter1++; 
            }
            else
            {
                x = iter1->second;
                // x = pattern_map[pattern[i]];
            }

            //index_s指向上一个word结束的地方
            if (index_s >= s.size())
                return false;
            index_s = index_s == 0 ? index_s : index_s + 1;
            temp = pullword(s, index_s);
            index_s += temp.size();   //要么指向空格要么指向s结尾
            // if ((auto iter = s_map.find(temp)) == s_map.end()) //没找到
            auto iter2 = s_map.find(temp);
            if (iter2 == s_map.end())   //没找到
            {
                y = counter2;
                s_map.insert({temp, counter2++});
                // s_map[temp] = counter2++; 
            }
            else
            {
                y = iter2->second;
                // y = s_map[temp];
            }
            if (x != y)
                return false;
        }

        index_s = index_s == 0 ? index_s : index_s + 1;
        if (index_s < s.size())
            return false;
    
        return true;
    }
private:
    //提取word
    string pullword(string &s, int i)
    {
        string temp = "";
        while (i < s.size() && s[i] != ' ')
        {
            temp.push_back(s[i++]);
        }
        return temp;
    }
};