#include <vector>
using std::vector;

class Solution {
public:
	int reverse(int x) {
		int po_ne;
		(x > 0) ? (po_ne = 1) : (po_ne = -1);
		x *= po_ne;
		vector<int> reverse;
		int temp;
		while (x != 0)
		{
			temp = x % 10;
			reverse.push_back(temp);
			x /= 10;
		}
		if (reverse.empty() == false)
		{
			vector<int>::iterator reIter = reverse.begin();
			for (; reIter != reverse.end(); ++reIter)
			{
				x *= 10;
				x += *reIter;
			}
			reIter = reverse.end() - 1;
			temp = *reIter;
			(temp != (x % 10)) ? (x = 0) : (x *= po_ne);
		}
		return x;
	}
};