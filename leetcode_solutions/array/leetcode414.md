# [414. 第三大的数](https://leetcode-cn.com/problems/third-maximum-number/)

## 1. 直接用 `set`

```cpp
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        auto it = s.rbegin();
        return (s.size() < 3) ? *it : *(++(++it));
    }
};
```

**复杂度分析**： 

- 时间复杂度：O(N)

- 空间复杂度：O(N) 



## 2. 维护一个长度为 `3` 的 `set`

```cpp
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s;
        
        for (auto i : nums)
        {
            s.insert(i);
            if (s.size() > 3)
            {
                s.erase(s.begin());
            }
        }

        return (s.size() < 3) ? (*s.rbegin()) : *(s.begin());
    }
};
```

​		**复杂度分析**

- 时间复杂度：O(N)
- 空间复杂度：O(1)