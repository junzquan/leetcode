# [1086. 前五科的均分](https://leetcode-cn.com/problems/high-five/)

```cpp
class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        map<int, vector<int>> ma;
        vector<vector<int>> res;
        
        for (auto& item : items)
        {
            ma[item[0]].push_back(item[1]);
        }
        
        for (auto& m : ma)
        {
            int sum = 0;
            int i = 0;
            sort(m.second.begin(), m.second.end(), greater);
            for (; i < m.second.size() && i < 5; i++)
            {
                sum += m.second[i];
            }
            res.push_back({m.first, sum / i});
        }
        
        return res;
    }
    
private:
    static bool greater(int i, int j)
    {
        return i > j;
    }
};
```

- 首先在哈希表 `ma` 中记录每个学生的各科成绩；
- 然后遍历 `ma`，对每个学生的成绩进行排序，并计算学生的前五科均分。

### 复杂度分析

- 时间复杂度：O(N)
- 空间复杂度：O(N)