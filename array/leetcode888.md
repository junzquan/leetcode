# [888. 公平的糖果交换](https://leetcode-cn.com/problems/fair-candy-swap/)

```cpp
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        vector<int> ans;
        int sum_A = 0;
        int sum_B = 0;
        for (auto i : A)
            sum_A += i;
        for (auto i : B)
            sum_B += i;
        int delta = (sum_B - sum_A) / 2;
        
        set<int> s;
        for (auto y : B)
            s.insert(y);
        for (auto x : A)
        {
            if (s.find(x + delta) != s.end())
            {
                ans.push_back(x);
                ans.push_back(x + delta);
                return ans;
            }
        }
        
        return ans;
    }
};
```

> 假设Alice给出x糖果，得到y糖果；那么Bob就会得到x糖果，y糖果。
>
> 设Alice和Bob的糖果总数分别为 S<sub>A</sub>, S<sub>B</sub> :
>
> ​			则 S<sub>A</sub> - x + y = S<sub>B</sub> + x - y
>
> ​			如果Bob有糖果 y = (S<sub>B</sub> - S<sub>A</sub>) / 2 + x 
>
> ​			就返回{x, y}			

