# [170. 两数之和 III - 数据结构设计](https://leetcode-cn.com/problems/two-sum-iii-data-structure-design/)

```cpp
class TwoSum {
public:
    /** Initialize your data structure here. */
    TwoSum():counts(unordered_map<int, int>()) {

    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        counts[number]++;
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for (auto it : counts)
        {
            int complement = value - it.first;
            if (complement != it.first && counts.find(complement) != counts.end())
                return true;
            if (complement == it.first && it.second > 1)
                return true;
        }
        return false;
    }

private:
    unordered_map<int, int> counts;
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */
```

- 用哈希表记录，键为数字，值为数字出现的次数；
- 查找时遍历哈希表，对于每个键值 `it.first` ，我们检查哈希表中是否存在 `value - it.first` ， 有则返回 `true` 。
- 当 `it.first == value - it.first` 时，如果哈希表中 `it.first` 的值大于 `2`， 也返回 `true` 。

### 复杂度分析

- `add(number)` 时间复杂度：O(1)
- `find(value)` 时间复杂度：O(N)
- 空间复杂度：O(N)



