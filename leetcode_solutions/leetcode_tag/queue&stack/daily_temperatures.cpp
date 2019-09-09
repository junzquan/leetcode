class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
    	std::vector<int> day(temperatures.size(), 0);
    	std::stack<int> s;
    	for (int i = 0; i < temperatures.size(); ++i) {
    		while (!s.empty() && temperatures[i] > temperatures[s.top()]){
    			day[s.top()] = i - s.top();
    			s.pop();
    		}
    		s.push(i);
    	}
    	return day;
    }
};