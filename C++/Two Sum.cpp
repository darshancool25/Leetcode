// https://leetcode.com/problems/two-sum/

/*Using sorting and two pointer method*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <pair<int, int>> vect;
        for (int i = 0; i < nums.size(); ++i) {
            vect.push_back({nums[i], i});
        }
        sort(vect.begin(), vect.end());
        int l = 0, r = nums.size() - 1;
        vector <int> ans(2);
        while (l < r) {
            if (vect[l].first + vect[r].first < target)l++;
            else if (vect[l].first + vect[r].first > target)r--;
            else {
                ans[0] = vect[l].second;
                ans[1] = vect[r].second;
                break;
            }
        }
        return ans;
    }
};


/*Using Map, without using upper bound*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map <int, vector<int>> mp;
        int sz = nums.size();
        for (int i = 0; i < sz; i++)
            mp[nums[i]].push_back(i);
        
        vector<int> ans(2);
        for (int i = 0; i < sz; i++) {
            int reqd = target - nums[i];
            if (mp[reqd].size() != 0) {
                int sz2 = mp[reqd].size();
                for (int j = 0; j < sz2; j++) {
                    if (i != mp[reqd][j]) {
                        ans[0] = i;
                        ans[1] = mp[reqd][j];
                    }
                }
            }
        }
        return ans;
    }
};


/*Using map and upper bound*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, vector<int>> mp;
        int sz = nums.size();
        for (int i = 0; i < sz; i++)mp[nums[i]].push_back(i);

        vector<int> ans(2);
        for (int i = 0; i < sz; i++) {
            int reqd = target - nums[i];
            if (mp[reqd].size() == 0)continue;
            auto it = upper_bound(mp[reqd].begin() , mp[reqd].end() , i);
            if (it != mp[reqd].end()) {
                ans[0] = i;
                ans[1] = *it;
            }
        }
        return ans;
    }
};
