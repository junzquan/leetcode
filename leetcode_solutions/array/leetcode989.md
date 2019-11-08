# [989. 数组形式的整数加法](https://leetcode-cn.com/problems/add-to-array-form-of-integer/)

```cpp
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> ret;
        int i = A.size();
        
        while (--i >= 0 || K > 0)
        {
            if (i >= 0)
                K += A[i];
            ret.push_back(K % 10);
            K /= 10;		// update K
        }
        
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
```

- 逐位相加，从 `A` 的个位开始，与 `K` 相加，将结果的个位加入结果 `ret`，然后更新 `K` ；
- 最后反转 `ret`。



### 复杂度分析

- 时间复杂度：O(max(N, log K))
- 空间复杂度：O(max(N, log K))



