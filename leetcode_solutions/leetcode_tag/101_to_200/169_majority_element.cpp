// Moore Voting Algorithm
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major, cnt = 0, n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (!cnt)
            {
                major = nums[i];
                cnt = 1;
            }
            else cnt += (major == nums[i]) ? 1 : -1;
        }
        return major;
    }
};