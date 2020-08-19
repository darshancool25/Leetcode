// https://leetcode.com/problems/min-cost-climbing-stairs/

/*O(n) Space*/
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < n; i++)
            dp[i] = cost[i] + min(dp[i - 1] , dp[i - 2]);
        return min(dp[n - 1], dp[n - 2]);
    }
};


/*O(1) Space*/
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int s1 = cost[0], s2 = cost[1];
        for (int i = 2; i < cost.size(); i++) {
            int temp = s2;
            s2 = min(s1, s2) + cost[i];
            s1 = temp;
        }
        return min(s1, s2);
    }
};
