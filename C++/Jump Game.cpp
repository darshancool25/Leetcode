// https://leetcode.com/problems/jump-game/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_reachable = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i <= max_reachable) {
                if (i + nums[i] > max_reachable)
                    max_reachable = i + nums[i];
            }
        }
        if (max_reachable >= nums.size() - 1)return true;
        else return false;
    }
};
