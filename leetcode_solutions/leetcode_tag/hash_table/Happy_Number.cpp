class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, int> happyMap;

        while (n != 1)
        {
            if (happyMap[n] == 0)
                happyMap[n]++;
            else
                return false;

            int sum = 0;
            while (n != 0)
            {
                sum += pow(n % 10, 2);
                n /= 10;
            }
            n = sum;
        }

        return true;
    }
};