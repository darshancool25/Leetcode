// https://leetcode.com/problems/jump-game-ii/

/*Short Explanation -
O(N^2) Dynamic Programming solution :
dp[i] = min moves to reach ith index
Initialise dp array with n+1 [as we know dp[i] is guaranteed to be less than n+1].
Start with dp[0] = 0 [Base Case]. Now for every index j reachable from index i in one move,
dp[j] = min(dp[j] , dp[i]+1).
Finally dp[n-1] is our answer.
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, n + 1);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n and j <= i + nums[i]; j++)
                dp[j] = min(dp[j],  dp[i] + 1);
        }
        return dp.back();
    }
};
