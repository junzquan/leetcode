#include <vector>
using std::vector;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> two_sum;
		for (auto beg1 = nums.cbegin(); beg1 != nums.cend(); ++beg1) {
			for (auto beg2 = (beg1 + 1); beg2 != nums.cend(); ++beg2) {
				if ((*beg1 + *beg2) == target) {
					two_sum.push_back(beg1 - nums.cbegin());
					two_sum.push_back(beg2 - nums.cbegin());
				}
			}
		}
		return two_sum;
	}
};