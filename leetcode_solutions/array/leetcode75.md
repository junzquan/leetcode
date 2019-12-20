# [66. 加一](https://leetcode-cn.com/problems/plus-one/)

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            if (digits[i] == 9)
            {
                digits[i] = 0;
            }
            else
            {
                digits[i]++;
                break;
            }
        }
        if (digits[0] == 0)
        {
            digits[0] = 1;
            digits.push_back(0);
        }
        return digits;
    }
};
```

- 当 `digits[i] == 9` 时，直接让 `digits[i] = 1`，进入下一轮循环；
- 直到 `digits[i] != 9`，然后 `digits[i]++`，退出循环；
- 如果是一个全为 `9` 的数，比如 `999`， 循环结束后 `digits` 的元素会全部为 `0`，这时令 `digits[0] = 1`，然后在数组最后加个 `0` 即可。



### 复杂度分析

- 时间复杂度：O(N)
- 空间复杂度：O(1)