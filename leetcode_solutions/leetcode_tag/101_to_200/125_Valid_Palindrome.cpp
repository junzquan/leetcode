class Solution {
public:
    bool isPalindrome(string s) {
		// C 库函数 int isalnum(int c) 检查所传的字符是否是字母和数字
        for (int i = 0, j = s.size() - 1; i < j; i++, j--)
        {
        	while (!isalnum(s[i]) && i < j) i++;
        	while (!isalnum(s[j]) && i < j) j--;
        	if (toupper(s[i]) != toupper(s[j])) return false;
        }
        return true;
    }
};


// 双指针，一个从左往右扫描，另一个从右往左扫描，直到它们相遇
// 跳过所有非字母和数字