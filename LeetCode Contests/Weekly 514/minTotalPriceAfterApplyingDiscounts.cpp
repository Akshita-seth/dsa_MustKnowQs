// Problem: Min Total Price After Applying Discounts
// https://leetcode.com/problems/minimum-total-price-after-applying-discounts/

// Greedy + Sorting Approach
// TC: O(nlogn) + O(mlogm) [sorting] + O(min(n,m)) [First loop] + O(n-m) [only if prices longer than discounts] Approx: O(nlogn + mlogm)
// SC: O(1)


class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        int n = prices.size();
        int m = discounts.size();

        double minP = 0.0;

        sort(prices.begin(), prices.end());
        sort(discounts.begin(), discounts.end());

        int i=n-1, j=m-1;

        while(i>=0 && j>=0)
            {
                minP += (prices[i] * (100.0 - discounts[j]))/100.0;
                i--, j--;
            }
        while(i>=0)
            {
                minP += prices[i];
                i--;
            }

        return minP;
    }
};
