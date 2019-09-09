class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> nums_set;
        for (auto n : nums)
        {
        	if (nums_set.count(n))
        		return true;
        	nums_set.insert(n);
        }
        return false;
    }
};