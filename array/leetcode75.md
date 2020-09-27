# [75. 颜色分类](https://leetcode-cn.com/problems/sort-colors/)(荷兰国旗问题)

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p0 = 0;
        int i  = 0;
        int p2 = nums.size() - 1;
        while (i <= p2)
        {
            if      (nums[i] == 0) swap(nums[i++], nums[p0++]);
            else if (nums[i] == 2) swap(nums[i],   nums[p2--]);
            else    i++;
        }
    }
};
```

- 实际上是使用了三向切分的快速排序的思想

### 复杂度分析

- 时间复杂度：O(N)
- 空间复杂度：O(1)



### 三向切分的快速排序

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int lo = 0;
        int hi = nums.size() - 1;
        threeWayQuickSort(nums, lo, hi);
    }
    
private:
    void threeWayQuickSort(vector<int>& nums, int lo, int hi)
    {
        if (hi <= lo + CUTOFF)
        {
            insertionSort(nums, lo, hi);
            return;
        }
        int lt = lo, gt = hi;
        int i = lo + 1;
        int v = nums[lo];
        while (i <= gt)
        {
            if (nums[i] < v)      swap(nums[lt++], nums[i++]);
            else if (nums[i] > v) swap(nums[gt--], nums[i]);
            else                  i++;
        }
        
        threeWayQuickSort(nums, lo, lt - 1);
        threeWayQuickSort(nums, gt + 1, hi);
    }
    
    void insertionSort(std::vector<int> &vec, int lo, int hi)
    {
        if (vec.size() < 2)
            return;
        for (int i = lo; i < hi + 1; i++)
            for (int j = i - 1; j >= 0 && vec[j] > vec[j + 1]; j--)
                swap(vec[j], vec[j + 1]);
    }
    
    static const int CUTOFF = 15;
};
```

