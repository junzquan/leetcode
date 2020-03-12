# [1071. 字符串的最大公因子](https://leetcode-cn.com/problems/greatest-common-divisor-of-strings/)

```cpp
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) return "";
        return str1.substr(0, gcd(str1.size(), str2.size()));
    }

private:
    inline int gcd(int a, int b) { return (b == 0) ? a : gcd(b, a % b); }
};
```

- 假设 `str1` 是由 `m` 个字符串 `X` 组成的，`str2` 是由 `n` 个字符串 `X` 组成的，那么 `m + n == n + m` ，也就是 `str1 + str2 == str2 + str1` 题目有解；
- 而 `X` 的长度应该是字符串 `str1` 和 `str2` 的长度的最大公约数。