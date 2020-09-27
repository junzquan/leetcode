# [1089. 复写零](https://leetcode-cn.com/problems/duplicate-zeros/)

```cpp
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int> copy = arr;
        int length = arr.size();
        arr.clear();
        for (int i = 0; i < length; i++)
        {
            arr.push_back(copy[i]);
            if (arr.size() >= length) return;
            if (copy[i] == 0) arr.push_back(copy[i]);
            if (arr.size() >= length) return;
        }
    }
};
```

