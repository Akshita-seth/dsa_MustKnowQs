// Problem: Best Time To Buy and Sell Stocks
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

// One pass scan problem. Keep track of minPrice. Compute the profit if sold today. Update maxProfit. Update minProce if today's price lower.
// TC: O(N) SC: O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0;
        for(int i=0; i< prices.size(); i++)
        {
            int p=prices[i];
            int profit = p - minPrice;
            maxProfit = max(maxProfit, profit);
            minPrice = min(minPrice, p);
        }
        return maxProfit;
    }
};

// Variation of Qs: If the buying and selling date as a vector {,} for max profit were also asked in question.
// TC: O(N) SC: O(1)


class Solution {
public:
    vector<int> maxProfitDays(vector<int>& prices) {
        int minPrice = prices[0], minDay = 0;
        int maxProfit = 0, buyDay = 0, sellDay = 0;

        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < minPrice) {
                minPrice = prices[i];
                minDay = i;
            }
            int profit = prices[i] - minPrice;
            if (profit > maxProfit) {
                maxProfit = profit;
                buyDay = minDay;
                sellDay = i;
            }
        }
        return {buyDay, sellDay}; // indices of buy and sell
    }
};
