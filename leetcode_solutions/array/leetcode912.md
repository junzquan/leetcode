# [912. 排序数组](https://leetcode-cn.com/problems/sort-an-array/)

## 快速排序

```cpp
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int lo = 0;
        int hi = nums.size() - 1;
        quickSort(nums, lo, hi);
        return nums;
    }
    
private:
    void quickSort(vector<int>& nums, int lo, int hi)
    {
        if (lo >= hi) return;
        int j = partition(nums, lo, hi);
        quickSort(nums, lo, j - 1);
        quickSort(nums, j + 1, hi);
    }
    
    int partition(vector<int>& nums, int lo, int hi)
    {
        int i = lo;
        int j = hi + 1;
        int v = nums[lo];
        while (true)
        {
            while (nums[++i] < v) if (i == hi) break;
            while (v < nums[--j]) if (j == lo) break;
            if (i >= j) break;
            swap(nums[i], nums[j]);
        }
        swap(nums[lo], nums[j]);
        return j;
    }
};
```

### 复杂度分析

- 时间复杂度：O(N*log N)
- 空间复杂度：O(1)