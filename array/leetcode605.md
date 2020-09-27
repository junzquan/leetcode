# [605. 种花问题](https://leetcode-cn.com/problems/can-place-flowers/)

```cpp
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        vector<int> vec = flowerbed;
        vec.insert(vec.begin(), 0);
        vec.push_back(0);

        int count = 0;
        int i = 1;
        while (i < vec.size() - 1)
        {
            if (vec[i] == 0 && vec[i - 1] == 0 && vec[i + 1] == 0)
            {
                count++;
                i += 2;
            }
            else
            {
                i++;
            }
        }
        return (count >= n);
    }
};
```

- 将数组前后补零，按题目要求判断即可。



### 复杂度分析

- 时间复杂度：O(N)
- 空间复杂度：O(N)