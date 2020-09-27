# [367. 有效的完全平方数](https://leetcode-cn.com/problems/valid-perfect-square/)

---

## 二分法

```cpp
class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 1) return true;
        int left = 0, right = num;
        while (left < right)
        {
            double mid = left + (right - left) / 2;
            if (mid < num / mid)
                left = mid + 1;
            else
                right = mid;
        }
        return (left == num / left);
    }
};
```

---

## 公式法

> 1+3+5+7+9+…+(2n-1)=n^2，即完全平方数肯定是前n个连续奇数的和

```cpp
class Solution {
public:
    bool isPerfectSquare(int num) {
        int i = 1;
        while (num > 0)
        {
            num -= i;
            i += 2;
        }
        return (num == 0);
    }
};
```

