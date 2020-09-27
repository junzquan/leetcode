# [268. 缺失数字](https://leetcode-cn.com/problems/missing-number/)

## 1. 数学

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int expectedSum = nums.size() * (nums.size() + 1) / 2;
        int actualSum = 0;
        for (auto i : nums)
            actualSum += i;
        return expectedSum - actualSum;
    }
};
```

- 等差数列求和公式求得0~n的和，再减去实际的和，得出结果。

  **复杂度分析**： 

- 时间复杂度：O(N)，需要遍历一次数组

- 空间复杂度：O(1) 



## 2.位运算

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int num = nums.size();
        for (int i = 0; i < nums.size(); i++)
        {
            num ^= i ^ nums[i];
        }
        return num;
    }
};
```

​		**复杂度分析**

- 时间复杂度：O(N)
- 空间复杂度：O(1)