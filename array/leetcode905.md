# [905. 按奇偶排序数组](https://leetcode-cn.com/problems/sort-array-by-parity/)

```cpp
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int left = 0;
        int right = A.size() - 1;
        while (left < right)
        {
            if (A[left] % 2 != 0 && A[right] % 2 == 0)
                swap(A[left], A[right]);
            if (A[left] % 2 == 0) left++;
            if (A[right] % 2 != 0) right--;
        }
        return A;
    }
};
```

