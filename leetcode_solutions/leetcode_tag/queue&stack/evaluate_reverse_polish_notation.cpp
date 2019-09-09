class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> num;
        for (string s : tokens) {
        	if (s == "+" || s == "-" || s == "*" || s == "/") {
        		int oper2 = num.top();
        		num.pop();
        		int oper1 = num.top();
        		num.pop();
        		if (s == "+")
       				oper1 += oper2;
       			else if (s == "-")
        			oper1 -= oper2;
        		else if (s == "*")
        			oper1 *= oper2;
        		else
        			oper1 /= oper2;

        		num.push(oper1);
        	} else {
        		num.push(stoi(s));
        	}
        }
        return num.top();
    }
};