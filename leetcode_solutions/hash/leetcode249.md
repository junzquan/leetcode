# [249. 移位字符串分组](https://leetcode-cn.com/problems/group-shifted-strings/)

## 哈希

```cpp
class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> res;
        unordered_map<string, int> hash_map;
        int index = 0;
        
        for (auto s : strings)
        {
            string key(s);
            if (key[0] != 'a')
            {
                for (int i = 1; i < s.length(); i++)
                    key[i] = (key[i] - key[0] + 26) % 26 + 'a';
                key[0] = 'a';
            }
            
            if (hash_map.count(key) != 0)
            {
                res[hash_map[key]].push_back(s);
                continue;
            }
            hash_map[key] = index++;
            res.push_back({s});
        }
        return res;
    }
};
```

- 利用哈希表建立字符串和 `vector` 对象索引之间的映射，并且哈希表中所有的键都是以 `a` 开头的字符串；
- 对 `strings` 中的每个字符串 `s` ，都将其转化为以 `a` 开头的字符串，如 `bcd -> abc` ，转化结果保存在 `key` 中；
- 当 `key` 已经出现过，通过哈希表获取 `key` 所在数组的索引，然后添加到数组中；
- 当 `key` 未出现过，将 `key` 加入到哈希表中，并将原字符串 `s` 加入结果数组。

### 复杂度分析

- 时间复杂度：O(N * k)， `k` 为最长的字符串的长度
- 空间复杂度：O(N)

