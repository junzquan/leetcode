class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> idx;
        int start = 0;
        int end = numbers.size() - 1;
        while (start < end)
        {
        	int sum = numbers[start] + numbers[end];
        	if (sum == target)
        	{
        		idx.push_back(start + 1);
        		idx.push_back(end + 1);
        		return idx;
        	}
        	else if (sum < target)
        	{
        		start++;
        	}
        	else
        	{
        		end--;
        	}
        }
        return idx;
    }
};