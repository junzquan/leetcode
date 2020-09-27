# [151. 翻转字符串里的单词](https://leetcode-cn.com/problems/reverse-words-in-a-string/)

```cpp
class Solution {
public:
    string reverseWords(string s) {
        stack<string> sta;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ') continue;
            int beg = i;
            while (i < s.length() && !isspace(s[i])) i++;
            sta.push(string(s, beg, i - beg));
        }

        string res;
        while (!sta.empty())
        {
            res += sta.top();
            sta.pop();
            if (!sta.empty()) res += " ";
        }

        return res;
    }
};
```

- 使用栈保存字符串中的每一个单词，最后拼接字符串即可。

### 复杂度分析

- 时间复杂度：O(N)
- 空间复杂度：O(N)