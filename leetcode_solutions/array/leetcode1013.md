# [1013. 将数组分成和相等的三个部分](https://leetcode-cn.com/problems/partition-array-into-three-parts-with-equal-sum/)

```cpp
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = 0;
        for (auto i : A) sum += i;
        if (sum % 3 != 0) return false;

        int cnt = 0;
        int part_sum = 0;
        int average = sum / 3;
        for (auto i : A)
        {
            part_sum += i;
            if (part_sum == average && cnt <= 2)
            {
                part_sum = 0;
                cnt++;
            }
            else if (i == A.size() - 1 && cnt == 2)
            {
                cnt++;
            }
        }

        return (cnt == 3) ? true : false;
    }
};
```

- 判断数组中所有数的和能否被3整除，不能直接返回false；
- 再次遍历数组，统计`part_sum == average`的次数，如果为3次，就可以将数组分为和相等的三份。