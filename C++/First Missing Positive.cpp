// https://leetcode.com/problems/first-missing-positive/

/*Solution using O(n) time and O(n) extra Space*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i, n = nums.size();
        vector<bool> marked(n, false);
        for (auto x : nums)if (x > 0 and x - 1 < n)marked[x - 1] = true;
        for (i = 0; i < n; i++)if (!marked[i])break;
        return i + 1;
    }
};


/*Solution using O(n) time and constant extra space
Short Explanation -
Rearrange the array so that all elements <=0 are to the left, others
to the right.
Then use the same array to mark the elements by changing sign from + to -.
Finally, if for some i>=j, nums[j]>0, then i-j+1 is the desired answer.
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i, j = 0, n = nums.size();
        for (auto &x : nums)
            if (x <= 0)swap(x, nums[j++]);
        for (int i = j; i < n; i++) {
            if (nums[i] > n)continue;
            int x = abs(nums[i]) - 1 + j;
            if (x >= 0 and x < n and nums[x]>0)nums[x] *= -1;
        }
        for (i = j; i < n; i++)if (nums[i] > 0)break;
        return i - j + 1;
    }
};
