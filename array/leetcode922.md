# [922. 按奇偶排序数组 II](https://leetcode-cn.com/problems/sort-array-by-parity-ii/)

## 双指针

```cpp
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int oddPtr = 1;
        int evenPtr = 0;
        int length = A.size();
        while (true)
        {
            while (oddPtr < length && A[oddPtr] % 2 == 1) oddPtr += 2;
            while (evenPtr < length && A[evenPtr] % 2 == 0) evenPtr += 2;
            if (oddPtr < length && evenPtr < length)
            {
                swap(A[oddPtr], A[evenPtr]);
            }
            else
            {
                break;
            }
        }
        return A;
    }
};
```

- 奇数指针寻找第一个在奇数位上的偶数；
- 偶数指针寻找第一个在偶数位上的奇数；
- 然后将它们交换；并循环操作这个过程。



### 复杂度分析

- 时间复杂度：O(N)
- 空间复杂度：O(1)