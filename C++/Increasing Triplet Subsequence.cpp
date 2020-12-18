// https://leetcode.com/problems/increasing-triplet-subsequence/

/*Short Explanation -
num and num 2 represents smallest and second smallest, but in order, i.e
first smallest will appear in array then second smallest will appear.
We update them accordingly at each step.
If at any point if elem is greater than second smallest, we have found an answer.
*/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int num = INT_MAX, num2 = INT_MAX;
        for (auto x : nums) {
            if (x < num)num = x;
            else if (x > num and x < num2)num2 = x;
            else if (x > num2)return true;
        }
        return false;
    }
};
