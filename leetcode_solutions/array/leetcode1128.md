# [1128. 等价多米诺骨牌对的数量](https://leetcode-cn.com/problems/number-of-equivalent-domino-pairs/)

```cpp
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> ret;
        int m = 0, n = 0, k = 0;
        for (auto& i : dominoes)
        {
            m = i[0];
            n = i[1];
            k = (m > n) ? (m * 10 + n) : (n * 10 + m);
            ret[k]++;
        }
        
        int count = 0;
        for (auto& i : ret)
        {
            count += i.second * (i.second - 1) / 2;
        }
        
        return count;
    }
};
```

- 首先遍历`dominoes`，将等价的多米诺骨牌映射到`map`中，统计出等价的多米诺骨牌数；
- 然后遍历`map`，用组合数学`n * (n - 1) / 2`求得每种骨牌成对的数目，累加之后得到最终结果。