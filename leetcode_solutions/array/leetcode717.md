# [717. 1比特与2比特字符](https://leetcode-cn.com/problems/1-bit-and-2-bit-characters/)

```cpp
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int lastZero = -1;
        for (int i = 0; i < bits.size(); i++)
        {
            if (bits[i] == 1)
                i += 1;
            else
                lastZero = i;
        }
        return lastZero == bits.size() - 1;
    }
};
```

- 遇到0跳一步，遇到1跳两步，因为遇到1就肯定遇到了2比特字符；
- 最后返回1比特字符0最后出现的位置是否为数组的最后一位。