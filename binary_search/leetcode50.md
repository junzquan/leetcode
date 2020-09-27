# [50. Pow(x, n)](https://leetcode-cn.com/problems/powx-n/)

---

## 递归

```cpp
class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if (N < 0)
        {
            x = 1 / x;
            N = -N;
        }
        return fastPow(x, N);
    }
    
private:
    double fastPow(double x, int n)
    {
        if (n == 0)
            return 1.0;
        double half = fastPow(x, n/2);
        if (n % 2 == 0)
            return half * half;
        else
            return half * half * x;
    }
};
```

---

