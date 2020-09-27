# [4. 寻找两个有序数组的中位数](https://leetcode-cn.com/problems/median-of-two-sorted-arrays/)

## 暴力法

```cpp
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> numsAll;
        for (auto i : nums1) numsAll.push_back(i);
        for (auto i : nums2) numsAll.push_back(i);
        sort(numsAll.begin(), numsAll.end());
        
        double res = 0;
        int m = numsAll.size();
        if (m % 2 == 0)
        {
            res = (numsAll[m / 2] + numsAll[m / 2 - 1]) / 2.0;
        }
        else
        {
            res = numsAll[m / 2];
        }
        return res;
    }
};
```

- 直接把两数组合并后排序，然后求得中位数。



