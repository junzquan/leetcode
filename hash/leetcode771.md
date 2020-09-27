# [771. 宝石与石头](https://leetcode-cn.com/problems/jewels-and-stones/)

```cpp
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> gems(J.begin(), J.end());
        int res = 0;
        for (char stone : S)
            if (gems.find(stone) != gems.end())
                res++;
        return res;
    }
};
```

### 复杂度分析

- 时间复杂度：O( max( length(J), length(S) ) )
- 空间复杂度：O(length(J))



