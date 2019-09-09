class Solution {
public:
    string reverseWords(string s) {
        string res;
        vector<string> vec;
        for (int i = 0; i < s.length(); i++)
        {
            int j = i;
            while (s[j] != ' ' && j < s.length()) j++;
            if (i != j)
            {
                string temp = s.substr(i, j - i);
                vec.push_back(temp);
                i = j;
            }
        }
        
        for (int i = vec.size() - 1; i != -1; i--)
        {
            res.append(vec[i]);
            if (i != 0) res.append(" ");
        }
        return res;
    }
};