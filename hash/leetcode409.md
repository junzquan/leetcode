# [409. 最长回文串](https://leetcode-cn.com/problems/longest-palindrome/)

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> _map;
        for (auto c : s) 
            _map[c]++;

        int res = 0;
        for (auto m : _map) 
            res += (m.second / 2) * 2;

        if (res < s.length()) 
            res++;

        return res;
    }
};
```

- 首先统计每个字符的出现次数；
- 每个字符有偶数个可以用来构成回文字符串；
- 当 `res < s.length()` 时， `s` 中一定有单个未使用的字符存在，可以把这个字符放到回文的最中间。

### 复杂度分析

- 时间复杂度：O(N)
- 空间复杂度：O(N)



