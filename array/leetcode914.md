# [914. 卡牌分组](https://leetcode-cn.com/problems/x-of-a-kind-in-a-deck-of-cards/)

```cpp
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> m;
        for (auto i : deck)
        {
            m[i]++;
        }
        
        int X = -1;
        for (auto i : m)
        {
            if (X == -1)
            {
                X = i.second;
            }
            else
            {
                X = gcd(X, i.second);
            }
        }
        
        return (X >= 2);
    }
    
private:
    int gcd(int x, int y)
    {
        return x == 0 ? y : gcd(y % x, x);
    }
};
```

- 首先使用哈希表记录每个元素的出现次数；
- 然后统计这些次数的最大公约数；
- 最后返回最大公约数是否大于等于 `2` 。



### 复杂度分析

- 时间复杂度：O(N log<sup>2</sup> N)
- 空间复杂度：O(N)