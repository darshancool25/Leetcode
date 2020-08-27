// https://leetcode.com/problems/find-right-interval/

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int sz = intervals.size();
        map <int, int> mp;
        for (int i = 0; i < sz; i++)mp[intervals[i][0]] = i;
        vector<int> ans(sz, -1);
        for (int i = 0; i < sz; i++) {
            auto it = mp.lower_bound(intervals[i][1]);
            if (it == mp.end())continue;
            ans[i] = (*it).second;
        }
        return ans;
    }
};
