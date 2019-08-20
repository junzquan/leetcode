# [981. 基于时间的键值存储](https://leetcode-cn.com/problems/time-based-key-value-store/)

```cpp
class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        s_[key].emplace(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        auto m = s_.find(key);
        if (m == s_.end()) return "";
        auto it = m->second.upper_bound(timestamp);
        if (it == begin(m->second)) return "";
        return prev(it)->second;
    }
    
private:
    unordered_map<string, map<int, string>> s_;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
```

