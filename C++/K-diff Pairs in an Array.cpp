// https://leetcode.com/problems/k-diff-pairs-in-an-array/

/*Short Explanation -
After sorting the given vector, we keep two pointers, l=0 and r=1 .
If difference, i.e nums[r] - nums[l] is greater than k we bring 'l' and 'r'
closer by doing l++. If difference is less than k we increase the difference
by doing r++. If difference is k, we have got a pair, so insert it into a set
as we need unique pairs.
NOTE : l == r isnt allowed
*/

// Time Complexity - O(n.log(n))
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (nums.size() <= 1)return 0;
        set <pair<int, int>> st;
        sort(nums.begin() , nums.end());
        int l = 0, r = 1;
        while (l < r and r < nums.size()) {
            int diff = nums[r] - nums[l];
            if (diff > k)l++;
            else if (diff == k) {
                st.insert({nums[l] , nums[r]});
                l++;
            }
            else r++;
            if (l == r)r++;
        }
        return st.size();
    }
};