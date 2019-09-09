class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        return decodeString(s, i);
    }

private:
    string decodeString(const string &s, int& i)
    {
        string res;
        while (i < s.length() && s[i] != ']')
        {
            if (!isdigit(s[i]))
                res += s[i++];
            else
            {
                // get num before '['
                int n = 0;
                while (i < s.length() && isdigit(s[i]))
                    n = n * 10 + s[i++] - '0';

                i++;    // skip '['
                string content = decodeString(s, i);
                i++;    // skip ']'

                while (n-- > 0)
                    res += content;
            }
        }
        return res;
    }
};