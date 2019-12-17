# [49. 字母异位词分组](https://leetcode-cn.com/problems/group-anagrams/)

```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ma;
        vector<vector<string>> res;
        for (auto& str : strs)
        {
            string temp = str;
            sort(temp.begin(), temp.end());
            ma[temp].push_back(str);
        }
        for (auto& m : ma)
        {
            res.push_back(m.second);
        }
        return res;
    }
};
```

- 对每个字符串进行排序，得到键值，然后将字符串放入哈希表中；
- 最后在将哈希表中的分组加入到 `vector` 中。

### 复杂度分析

- 时间复杂度：O(N*logN)
- 空间复杂度：O(N)



