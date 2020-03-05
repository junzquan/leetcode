# [841. 钥匙和房间](https://leetcode-cn.com/problems/keys-and-rooms/)

## 广度优先搜索

```cpp
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        const int OPEN = 1;
        const int CLOSE = 0;

        int roomNum = rooms.size();
        vector<int> openedRoom(roomNum, 0);
        openedRoom[0] = 1;

        queue<int> keys;
        for (auto key : rooms[0]) keys.push(key);

        while (!keys.empty())
        {
            int key = keys.front();
            keys.pop();
            if (openedRoom[key] == OPEN) continue;
            for (auto newKey : rooms[key]) keys.push(newKey);
            openedRoom[key] = OPEN;
        }

        for (auto room : openedRoom)
            if (room == CLOSE)
                return false;
        
        return true;
    }
};
```

### 复杂度分析

- 时间复杂度：O(N + E)，E是钥匙的数量；
- 空间复杂度：O(E)

