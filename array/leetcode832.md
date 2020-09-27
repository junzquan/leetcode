# [832. 翻转图像](https://leetcode-cn.com/problems/flipping-an-image/)

```cpp
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for (auto& vec: A)
        {
            int length = vec.size();
            for (int i = 0; i < length / 2; i++)
            {
                int temp = vec[i];
                vec[i] = vec[length - 1 - i];
                vec[length - 1 - i] = temp;
                vec[i] ^= 1; 
                vec[length - 1 - i] ^= 1;
            }
            if (length % 2 != 0)
                vec[length / 2] ^= 1;
        }
        return A;
    }
};
```

