# [744. 寻找比目标字母大的最小字母](https://leetcode-cn.com/problems/find-smallest-letter-greater-than-target/)

```cpp
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0, right = letters.size();
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (letters[mid] > target)
                right = mid;
            else
                left = mid + 1;
        }
        return letters[left % letters.size()];  // 注意
    }
};
```

- 如果`target`比`letters`中所有元素都大，则返回第一个元素

