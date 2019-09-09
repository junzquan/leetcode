class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> res;
        unordered_map<string, int> map1;
        int min = INT_MAX;
        
        for (int i = 0; i < list1.size(); i++)
            map1[list1[i]] = i;
        
        for (int i = 0; i < list2.size(); i++)
        {
            if (map1.count(list2[i]) != 0)
            {
                if (map1[list2[i]] + i < min)
                {
                    min = map1[list2[i]] + i;
                    res.clear();
                    res.push_back(list2[i]);
                }
                else if (map1[list2[i]] + i == min)
                    res.push_back(list2[i]);
            }
        }
        
        return res;
    }
};