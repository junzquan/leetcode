# [88. 合并两个有序数组](https://leetcode-cn.com/problems/merge-sorted-array/)

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (m == 0 && n == 0) return;
        int pos = m + n - 1;
        m--;
        n--;
        
        while (m >= 0 && n >= 0)
        {
            if (nums1[m] > nums2[n])
            {
                nums1[pos--] = nums1[m--];
            }
            else
            {
                nums1[pos--] = nums2[n--];
            }
        }
        
        while (m >= 0)
        {
            nums1[pos--] = nums1[m--];
        }
        
        while (n >= 0)
        {
            nums1[pos--] = nums2[n--];
        }
    }
};
```

- 倒用双指针，从后往前添加元素。



### 复杂度分析

- 时间复杂度：O(M + N)
- 空间复杂度：O(1)