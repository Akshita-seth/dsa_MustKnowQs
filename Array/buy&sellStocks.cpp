// Problem: Best Time To Buy and Sell Stocks
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Pattern of Optimization: This is a classic greedy pattern: make the best local decision (track min price) to achieve the global optimum (max profit).



// DND
// this code only compares adjacent prices (prices[i+1] - prices[i]). That will catch small day‑to‑day changes, 
// but it misses the real essence of the Best Time to Buy and Sell Stock problem: you’re allowed to buy on one day and sell on any later day, not just the next one.

//BFS: TC(N^2) SC:O(1) 
//Approach: Explore all possible ways to buy and sell stock. Nested i and j.

int maxProfit(vector<int> &prices) {  
    int n = prices.size();
    int profit = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
			profit = max(res, prices[j] - prices[i]);
        }
    }
    return profit;
}


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
