#include <map>
#include <utility>
#include <string>
using std::string;
using std::map;
using std::pair;

class Solution {
public:
	int romanToInt(string s) {
		map<string, int> romanInt;
		romanInt.insert(pair<string, int>("I", 1));
		romanInt.insert(pair<string, int>("V", 5));
		romanInt.insert(pair<string, int>("X", 10));
		romanInt.insert(pair<string, int>("L", 50));
		romanInt.insert(pair<string, int>("C", 100));
		romanInt.insert(pair<string, int>("D", 500));
		romanInt.insert(pair<string, int>("M", 1000));
		romanInt.insert(pair<string, int>("IV", 4));
		romanInt.insert(pair<string, int>("IX", 9));
		romanInt.insert(pair<string, int>("XL", 40));
		romanInt.insert(pair<string, int>("XC", 90));
		romanInt.insert(pair<string, int>("CD", 400));
		romanInt.insert(pair<string, int>("CM", 900));

		int _Int = 0;
		string::iterator sIter = s.begin();
		map<string, int>::iterator libIter = romanInt.begin();
		string temp, temp1;
		for (; sIter != s.end(); ++sIter) { 
			if (sIter != s.end() - 1) {
				temp1 = *(sIter + 1);
				temp = (*sIter) + temp1;
				if (romanInt.end() != romanInt.find(temp)) {
					libIter = romanInt.find(temp);
					_Int += libIter->second;
					++sIter;
					continue;
				}
			}
			temp = *sIter;
			libIter = romanInt.find(temp);
			_Int += libIter->second;
			
		}
		return _Int;
	}
};

#include <iostream>

int main() {
	while (true)
	{
		string st;
		std::cin >> st;
		Solution s;
		std::cout << s.romanToInt(st) << std::endl;
	}
	system("pause");
	return 0;
}