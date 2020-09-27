# [454. 四数相加 II](https://leetcode-cn.com/problems/4sum-ii/)

```cpp
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> sumAB;
        int res = 0;
        for (auto numA : A)
        {
            for (auto numB : B)
            {
                sumAB[numA + numB]++;
            }
        }

        for (auto numC : C)
        {
            for (auto numD : D)
            {
                auto it = sumAB.find(-(numC + numD));
                if (it != sumAB.end())
                    res += it->second;
            }
        }

        return res;
    }
};
```

- 首先求出数组 `A` 和 `B` 任意两数之和 `sumAB` ，并 `sumAB` 为键， `sumAB` 出现的次数为值，存入哈希表中；
- 然后求出数组 `C` 和 `D` 任意两数之和的相反数 `sumCD` ，在哈希表中查找是否存在以 `sumCD` 为键的值，如果存在则将其加入到结果 `res` 中。 

### 复杂度分析

- 时间复杂度：O(N<sup>2</sup>)
- 空间复杂度：O(N<sup>2</sup>)



