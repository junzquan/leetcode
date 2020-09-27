# [3. 无重复字符的最长子串](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/)

## 暴力

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        const int n = s.length();
        for (int i = 0; i < n; i++)
        {
            vector<int> seen(128, 0);
            int j = i;
            while (j < n && !seen[s[j]])
                seen[s[j++]]++;
            res = max(res, j - i);
        }
        return res;
    }
};
```

### 复杂度分析

- 时间复杂度：O(N<sup>2</sup>) => O(N * 128)
- 空间复杂度：O(128)



## 滑动窗口

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        const int n = s.length();
        vector<int> index(128, -1);
        for (int i = 0, j = 0; j < n; j++)
        {
            i = max(i, index[s[j]] + 1);
            res = max(res, j - i + 1);
            index[s[j]] = j;
        }
        return res;
    }
};
```

### 复杂度分析

- 时间复杂度：O(N)
- 空间复杂度：O(1)