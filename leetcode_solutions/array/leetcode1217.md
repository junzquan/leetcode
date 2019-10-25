# [1217. 玩筹码](https://leetcode-cn.com/problems/play-with-chips/)

```cpp
class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        int odd = 0;
        int even = 0;
        for (auto i : chips)
            (i % 2 == 0) ? even++ : odd++;
        return min(odd, even);
    }
};
```

#### 两种情况

- 将所有奇数位置的筹码移动到任意一个偶数位置（总代价为这些筹码的个数`odd`），其余筹码（都在偶数位置）移动到该偶数位置上（总代价为`0`）；
- 将所有偶数位置的筹码移动到任意一个奇数位置（总代价为这些筹码的个数`even`），其余筹码（都在奇数位置）移动到该奇数位置上（总代价为`0`）；
- 最后比较`odd`和`even`

