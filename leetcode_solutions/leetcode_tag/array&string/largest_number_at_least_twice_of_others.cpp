class Solution 
{
public:
    int dominantIndex(vector<int>& nums) 
    {
    	if (nums.empty())
    		return -1;

    	int idx = 0, max = INT_MIN, lastMax = INT_MIN;

        for (int i = 0; i < nums.size(); i++)
        {
        	if (nums[i] > max) 
        	{
        		lastMax = max;
        		max = nums[i];
        		idx = i;
        	} 
        	else if (nums[i] > lastMax)
        	{
        		lastMax = nums[i];
        	}
		}
        
        if (max >= lastMax * 2)
        	return idx;
        return -1;
    }
};