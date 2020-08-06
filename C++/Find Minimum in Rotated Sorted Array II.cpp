// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/

//Simple binary Search with some tweaks
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[high] == nums[mid])high--;
            else if (nums[mid] > nums[high])low = mid + 1;
            else high = mid;
        }
        return nums[high];
    }
};
