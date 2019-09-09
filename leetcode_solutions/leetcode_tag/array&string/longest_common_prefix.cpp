class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    	string res = "";
    	int len = 0;
    	if (strs.empty())
    		return res;
    	while (true)
    	{
    		char c = strs[0][len];
    		for (auto& s : strs)
    		{
    			if (len == s.length()) return res;
    			if (c != s[len]) 	   return res;
    		}
    		++len;
    		res += c;
    	}


        return res;
    }
};