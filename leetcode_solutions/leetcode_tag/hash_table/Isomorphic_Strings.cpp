class Solution {
public:
    bool isIsomorphic(string s, string t) {
  		unordered_map<char, int> hash_s, hash_t;
  		for (int i = 0; i < s.size(); i++)
  		{
  			if (hash_s[s[i]] != hash_t[t[i]])
  				return false;
  			hash_s[s[i]] = i + 1;
  			hash_t[t[i]] = i + 1;
  		}      
  		return true;
    }
};