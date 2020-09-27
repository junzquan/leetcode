# [1122. 数组的相对排序](https://leetcode-cn.com/problems/relative-sort-array/)

```cpp
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> res;
        map<int, int> ma;

        for (auto i : arr1)
        {
            ma[i]++;
        }
        
        for (auto j : arr2)
        {
            int times = ma[j];
            for (int k = 0; k < times; k++)
            {
                res.push_back(j);
            }
            ma.erase(j);
        }
        
        for (auto& m : ma)
        {
            int times = m.second;
            for (int k = 0; k < times; k++)
            {
                res.push_back(m.first);
            }
        }
        
        return res;
    }
};
```

- 首先遍历 `arr1`，用 `map` 统计 `arr1` 中各个数的出现次数；
- 然后遍历 `arr2`，对于 `arr2` 中的每个数 `j`，可以从 `map` 中获取 `j` 在 `arr1` 中出现的次数 `times`，于是把 `j` 加入结果数组 `times` 次， 并把 `j` 从 `map` 中消除；
- 最后遍历 `map` 中剩下的元素，并把它们加入结果数组 `res` 中。

### 复杂度分析

- 时间复杂度：O(N)，`N` 为数组 `arr1` 的长度；
- 空间复杂度：O(N)