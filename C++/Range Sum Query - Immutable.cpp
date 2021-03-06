// https://leetcode.com/problems/range-sum-query-immutable/
/*Dynamic Programming, Prefix Sum*/

class NumArray {
public:
    vector <int> dp;
    NumArray(vector<int>& nums) {
        if (nums.size() == 0)return;
        dp = vector<int>(nums.size());
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
            dp[i] += nums[i] + dp[i - 1];
    }

    int sumRange(int i, int j) {
        return dp[j] - ((i > 0) ? dp[i - 1] : 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
