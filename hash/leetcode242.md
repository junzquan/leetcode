# [242. 有效的字母异位词](https://leetcode-cn.com/problems/valid-anagram/)

## 哈希

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> m;
        for (auto c : s) m[c]++;
        for (auto c : t) m[c]--;

        for (auto it : m)
        {
            if (it.second != 0) return false;
        }
        return true;
    }
};
```

- 使用一个哈希表记录 `s` 中字符出现频率；
- 然后遍历 `t` 中字符，对相应字符在哈希表中出现的次数递减；
- 如果两个字符串是字母异位词，则哈希表中所有元素的次数应该为 `0`。

### 复杂度分析

- 时间复杂度：O(N)
- 空间复杂度：O(1)



## 排序

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};
```

### 复杂度分析

- 时间复杂度：O(N log N)
- 空间复杂度：O(1)



