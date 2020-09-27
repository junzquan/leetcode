# [162. 寻找峰值](https://leetcode-cn.com/problems/find-peak-element/)

```cpp
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[mid + 1])
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};
```

- 如果`nums[ mid ] > nums[ mid + 1 ]`，则mid左边一定会有峰值；
- 如果`nums[ mid ] < nums[ mid + 1 ]`，则mid右边一定会有峰值；
- mid不会取到最右的元素，因为如果`mid == nums.size() - 1`，则`left == right`终止循环。