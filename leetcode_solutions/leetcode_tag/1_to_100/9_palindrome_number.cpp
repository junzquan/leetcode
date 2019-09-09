#include <iostream>
#include <vector>
using std::vector;

class Solution {
public:
	bool isPalindrome(int x) {
		bool result;
		if (x < 0) {
			result = false;
		}
		else {
			vector<int> palindromeVec;
			int temp = x;
			while (temp != 0)
			{
				palindromeVec.push_back(temp % 10);
				temp /= 10;
			}
			vector<int>::iterator reIter = palindromeVec.begin();
			for (; reIter != palindromeVec.end(); ++reIter) {
				temp *= 10;
				temp += *reIter;
			}
			(temp == x) ? (result = true) : (result = false);
		}
		return result;
	}
};

int main() {
	while (true)
	{
		int i;
		std::cin >> i;
		Solution s;
		bool bo = s.isPalindrome(i);
		std::cout << bo << std::endl;
	}
	system("pause");
	return 0;
}