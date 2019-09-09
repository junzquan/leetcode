class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int left = 0, right = 0, sum = 0, n = nums.size(), minlen = INT_MAX;
        while (right < n)
        {
        	do sum += nums[right++];
        	while (right < n && sum < s);
        	while (left < right && sum - nums[left] >= s)
        		sum -= nums[left++];
        	if (sum >= s) minlen = min(minlen, right - left);
        }

        return minlen == INT_MAX ? 0 : minlen;
    }
};