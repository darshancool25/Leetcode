// https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3)return vector<vector<int>>();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size() - 2;)
        {
            int j = i + 1, k = nums.size() - 1;
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0)
                {
                    vector <int> temp{nums[i], nums[j], nums[k]};
                    if (ans.empty() or temp != *ans.rbegin())ans.push_back(temp);
                    ++j, --k;
                }
                else if (sum > 0)k--;
                else j++;
            }
            int tmp = nums[i];
            while (i < nums.size() and tmp == nums[i])i++;
        }
        return ans;
    }
};
