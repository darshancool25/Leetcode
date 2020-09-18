// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

/*
Quick Explanation -
Try and sell stock at each day and update ans variable.
The buying cost will be minimum of prices till current index.
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0)return 0;
        int minn = prices[0], ans = 0;
        for (auto x : prices) {
            if (x < minn)minn = x;
            ans = max(ans, x - minn);
        }
        return ans;
    }
};
