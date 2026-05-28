class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int l = 0; // buy
        int r = 1; // sell

        int maxProfit = 0;

        while (r < prices.size()) {

            // profitable
            if (prices[r] > prices[l]) {

                int profit = prices[r] - prices[l];
                maxProfit = max(maxProfit, profit);

            } 
            // found cheaper buy price
            else {

                l = r;
            }

            r++;
        }

        return maxProfit;
    }
};