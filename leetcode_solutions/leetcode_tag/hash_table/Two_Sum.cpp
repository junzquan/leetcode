class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> hash;

        // key is the number and value is the index of nums
        for (int i = 0; i < nums.size(); i++)
        {
            int numToFind = target - nums[i];

            if (hash.find(numToFind) != hash.end())
            {
                res.push_back(hash[numToFind]);
                res,push_back(i);
                return res;
            }
            hash[numToFind] = i;
        }
        return res;
    }
};