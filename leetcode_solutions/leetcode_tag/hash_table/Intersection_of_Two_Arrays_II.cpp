class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums1.size(); i++)
        {
            map[nums1[i]]++;
        }
        
        vector<int> res;
        for (auto &i : nums2)
        {
            if (map[i] > 0)
            {
                res.push_back(i);
                map[i]--;
            }
        }
        return res;
    }
};