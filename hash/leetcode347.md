# [347. 前 K 个高频元素](https://leetcode-cn.com/problems/top-k-frequent-elements/)

## 哈希

```cpp
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        for (auto i : nums) counts[i]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for (const auto& m : counts)
        {
            minHeap.push(make_pair(m.second, m.first));
            if (minHeap.size() > k) minHeap.pop();
        }

        vector<int> res;
        for (int i = 0; i < k; i++)
        {
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }
        reverse(res.begin(), res.end());

        return res;
    }
};
```

- 使用哈希表记录每个数字的出现次数；
- 然后维护一个大小为 `k` 的小根堆；
- 最后得到出现频率前 `k` 高的数字。

### 复杂度分析

- 时间复杂度：O(N)
- 空间复杂度：O(N)



