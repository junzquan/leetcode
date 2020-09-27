# [1051. 高度检查器](https://leetcode-cn.com/problems/height-checker/)

```cpp
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> cnts(101, 0);
        for (auto h : heights)
            cnts[h]++;
        int ans = 0;
        for (int i = 1, j = 0; i < cnts.size(); i++)
        {
            while (cnts[i]-- > 0)
            {
                if (heights[j++] != i)
                    ans++;
            }
        }
        return ans;
    }
};
```

- 首先对各个高度进行计数；
- 然后遍历`heights`，统计不在位置上的数。