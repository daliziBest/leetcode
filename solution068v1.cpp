class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        string line;
        int start = 0;
        int end;
        while (true) {
            //determine the strings that a line contains
            //[start, end)
            int charNum = words[start].size();
            for (end = start + 1; end < words.size(); end++) {
                if (charNum + 1 + words[end].size() <= maxWidth) {
                    charNum = charNum + 1 + words[end].size();
                } else {
                    break;
                }
            }
            //determine if it is the last line
            if (end == words.size()) {
                break;
            }
            //if not the last line
            if (end - start > 1) {
                int spaceNum = maxWidth - charNum + (end - start - 1);
                int a = spaceNum / (end - start - 1);
                int b = spaceNum % (end - start - 1);
                line.append(words.at(start));
                for (int i = start + 1; i < end; i++) {
                    //append space
                    if (b != 0) {
                        line.append(a + 1, ' ');
                        b--;
                    } else {
                        line.append(a, ' ');
                    }
                    //append word
                    line.append(words.at(i));
                }
            } else {
                line.append(words.at(start));
                line.append(maxWidth - words[start].size(), ' ');
            }
            result.push_back(line);

            line.clear();
            start = end;
        }

        //if the last line
        line.append(words.at(start));
        for (int i = start + 1; i < end; i++) {
            line += ' ' + words.at(i);
        }
        line.append(maxWidth - line.size(), ' ');
        result.push_back(line);

        return result;
    }
};