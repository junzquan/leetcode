# [380. 常数时间插入、删除和获取随机元素](https://leetcode-cn.com/problems/insert-delete-getrandom-o1/)

## 哈希

```cpp
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet():valueToIndexMap(unordered_map<int,int>()), nums(vector<int>()) {

    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (valueToIndexMap.find(val) != valueToIndexMap.end())
            return false;

        nums.push_back(val);
        int index = nums.size() - 1;
        valueToIndexMap[val] = index;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (valueToIndexMap.find(val) == valueToIndexMap.end())
            return false;
        
        // 将需要移除的元素和数组最后一个元素交换
        int lastIndex = nums.size() - 1;
        int removeValIndex = valueToIndexMap[val];
        int lastNum = nums[lastIndex];
        swap(nums[removeValIndex], nums[lastIndex]);
        
        // 删除数组最后一个元素
        nums.pop_back();
        
        // 更新被交换元素的索引
        valueToIndexMap[lastNum] = removeValIndex;
        
        // 将哈希表中val元素删除
        valueToIndexMap.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int randomIndex = rand() % nums.size();
        return nums[randomIndex];
    }

private:
    unordered_map<int, int> valueToIndexMap;
    vector<int> nums;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
```

