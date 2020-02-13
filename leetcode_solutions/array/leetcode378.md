# [378. 有序矩阵中第K小的元素](https://leetcode-cn.com/problems/kth-smallest-element-in-a-sorted-matrix/)

```cpp
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int, vector<int>, less<int>> pq;
        int res = 0;
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[0].size(); j++)
            {
                pq.push(matrix[i][j]);
                if (pq.size() > k) pq.pop();
                res = pq.top();
            }
            
        return res;
    }
};
```

- 堆解法

**复杂度分析**： 

- 时间复杂度：O(N)

- 空间复杂度：O(k) 


