//                   sum(P) - sum(N) = target
// sum(P) + sum(N) + sum(P) - sum(N) = target + sum(P) + sum(N)
//                        2 * sum(P) = target + sum(nums)

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum < S || (sum + S) & 1)
            return 0;
        int s = (S + sum) / 2;
        vector<int> dp(s + 1, 0);
        dp[0] = 1;
        for (auto num : nums)
            for (int i = s; i >= num; --i)
                dp[i] += dp[i - num];
        return dp[s];
    }
};