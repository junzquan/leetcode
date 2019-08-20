# [658. 找到 K 个最接近的元素](https://leetcode-cn.com/problems/find-k-closest-elements/)

```cpp
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // find left boundry
        int left = 0, right = arr.size() - k;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (abs(x - arr[mid]) > abs(x - arr[mid + k]))
                left = mid + 1;
            else
                right = mid;
        }
        
        return vector<int>(arr.begin() + left, arr.begin() + left + k);
    }
};
```

- 找出左边界，如果`abs(x - arr[mid]) > abs(x - arr[mid + k])`，则做边界一定在右侧，否则在左侧。

