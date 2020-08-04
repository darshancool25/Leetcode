// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		const int n = prices.size();
		int empty = 0, hold = INT_MIN, cooldown = 0;
		for (int i = 0; i < n; ++i)
			tie(empty, hold, cooldown) = make_tuple(max(empty, cooldown), max(hold, empty - prices[i]), hold + prices[i]);
		return max(empty, cooldown);
	}
};