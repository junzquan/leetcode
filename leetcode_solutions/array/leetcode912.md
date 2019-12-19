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
        if (hi <= lo) return;
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

- 用时 76 ms，击败 65.83% 的用户。

### 复杂度分析

- 时间复杂度：O(N*log N)
- 空间复杂度：O(1)

### 使用插入排序处理子数组的快速排序

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
        // 当子数组大小小于等于10时，使用插入排序
        int M = 10;
        if (hi <= lo + M) { insertionSort(nums, lo, hi); return; }
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
    
    void insertionSort(std::vector<int> &vec, int lo, int hi)
    {
        if (vec.size() < 2)
            return;
        for (int i = lo; i < hi + 1; i++)
            for (int j = i - 1; j >= 0 && vec[j] > vec[j + 1]; j--)
                swap(vec[j], vec[j + 1]);
    }
};
```

- 在处理规模较小的数组时，插入排序比快速排序要快。
- 用时 64 ms，击败 98.09% 的用户。