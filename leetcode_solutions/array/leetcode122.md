# [122. 买卖股票的最佳时机 II](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/)

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int profit = 0;
        for (int i = 0; i < prices.size() - 1; i++)
        {
            // 只将上涨交易日的利润计入profit
            if (prices[i + 1] > prices[i])
            {
                profit += prices[i + 1] - prices[i];
            }
        }
        return profit;
    }
};
```

- 单独交易日：今天买入，明天卖出，则利润为 p<sub>i+1</sub> - p<sub>i</sub>（负数为亏损）；
- 连续上涨交易日：设这些天的价格分别为p<sub>1</sub>, p<sub>2</sub>, ..., p<sub>n</sub>，总利润为 p<sub>n</sub> - p<sub>1</sub>，则相当于每日都交易， p<sub>n</sub> - p<sub>1</sub> =  

 (p<sub>2</sub> - p<sub>1</sub>) + ( p<sub>3</sub> - p<sub>2</sub>) + ... + ( p<sub>n</sub> - p<sub>n-1</sub>)；

- 连续下跌交易日：不交易。

###### 复杂度分析

- 时间复杂度：O(N)，只遍历一次`prices`；
- 空间复杂度：O(1)，只使用常数额外空间。

