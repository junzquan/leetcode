class Solution {
public:
    int firstUniqChar(string s) {
        int index = INT_MAX;
        unordered_map<char, int> map;
        
        for (int i = 0; i < s.size(); i++)
        {
            if (map.find(s[i]) == map.end())
                map[s[i]] = i;
            else
                map[s[i]] = INT_MAX;
        }
        
        for (auto &c : map)
        {
            index = min(c.second, index);
        }
        
        return (index == INT_MAX) ? -1 : index;
    }
};