// https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <pair<int, int>> vect;
        for (int i = 0; i < nums.size(); ++i){
            vect.push_back({nums[i], i});
        }
        sort(vect.begin(), vect.end());
        int l = 0, r = nums.size() - 1;
        vector <int> ans(2);
        while (l < r){
            if (vect[l].first + vect[r].first < target)l++;
            else if (vect[l].first + vect[r].first > target)r--;
            else{
                ans[0] = vect[l].second;
                ans[1] = vect[r].second;
                break;
            }
        }
        return ans;
    }
};
