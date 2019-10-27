# [977. 有序数组的平方](https://leetcode-cn.com/problems/squares-of-a-sorted-array/)

### 排序

```cpp
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        for (auto& a : A)
            a *= a;
        sort(A.begin(), A.end());
        return A;
    }
};
```

- 先对数组每个数平方，最后排序。

---

### 双指针

```cpp
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int left = 0;
        int right = A.size() - 1;
        vector<int> ans(A.size(), 0);
        int pos = ans.size() - 1;
        while (left <= right)
        {
            if (A[left] * A[left] >= A[right] * A[right])
            {
                ans[pos] = A[left] * A[left];
                left++;
                pos--;
            }
            else
            {
                ans[pos] = A[right] * A[right];
                right--;
                pos--;
            }
        }
        return ans;
    }
};
```

- 因为数组是非递减的，平方最大只会出现在数组两侧，所以可以将左右指针向中间扫描，按顺序从大到小得到答案数组。