class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> numSet1{nums1.begin(), nums1.end()}, numSet2;
        for (int i = 0; i < nums2.size(); i++)
        {
        	if (numSet1.count(nums2[i]))
        		numSet2.insert(nums2[i]);
        }
        vector<int> inter{numSet2.begin(), numSet2.end()};
        return inter;
    }
};