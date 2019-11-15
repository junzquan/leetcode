# [189. 旋转数组](https://leetcode-cn.com/problems/rotate-array/)

## 1. 使用临时数组

```cpp
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> temp;
        int length = nums.size();
        k %= length;
        for (int i = length - k; i < length; i++)
        {
            temp.push_back(nums[i]);
        }
        
        for (int i = length - 1 - k; i >= 0; i--)
        {
            nums[i + k] = nums[i];
        }
        
        for (int i = 0; i < temp.size(); i++)
        {
            nums[i] = temp[i];
        }
    }
};
```

- 将 `nums` 后 `k` 个元素记录到临时数组中；
- 然后剩下的元素往后挪；
- 最后将临时数组中的元素放回 `nums` 中。

### 复杂度分析：

- 时间复杂度：O(N)
- 空间复杂度：O(N)



## 2. 反转数组

```cpp
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int length = nums.size();
        k %= length;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
```

- 首先反转数组 `nums` ；
- 然后反转 `nums` 的前 `k` 个数；
- 最后反转剩下的数。

### 复杂度分析：

- 时间复杂度：O(N)
- 空间复杂度：O(1)





