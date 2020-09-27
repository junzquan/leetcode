# [359. 日志速率限制器](https://leetcode-cn.com/problems/logger-rate-limiter/)

## 哈希

```cpp
class Logger {
public:
    /** Initialize your data structure here. */
    Logger(): m_map(unordered_map<string, int>()) {

    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        auto iter = m_map.find(message);
        if (iter != m_map.end() && abs(timestamp - iter->second) < 10)
            return false;
        m_map[message] = timestamp;
        return true;
    }

private:
    unordered_map<string, int> m_map;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
```

### 复杂度分析

- 时间复杂度：O(1)
- 空间复杂度：O(N)



