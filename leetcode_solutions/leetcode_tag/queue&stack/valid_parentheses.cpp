class Solution {
public:
    bool isValid(string s) {
        stack<char> match;
        for (char& c : s) {
        	if (c == '(' || c == '{' || c == '[')
        		match.push(c);
        	else {
        		if (match.empty()) return false;
        		if (c == ')' && match.top() != '(')
        			return false;
        		if (c == ']' && match.top() != '[')
        			return false;
        		if (c == '}' && match.top() != '{')
        			return false;
        		match.pop();
        	}
        }
        return match.empty();
    }
};