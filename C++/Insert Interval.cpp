// https://leetcode.com/problems/insert-interval/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int i = 0, n = intervals.size();
        if (n == 0)return {newInterval};
        if (intervals[n - 1][1] < newInterval[0]) {
            intervals.push_back(newInterval);
            return intervals;
        }
        for (i = 0; i < n; i++) {
            if (intervals[i][1] < newInterval[0])ans.push_back(intervals[i]);
            else {
                int l, r;
                l = min(newInterval[0] , intervals[i][0]);
                r = newInterval[1];
                while (i<n and r >= intervals[i][0])
                    r = max(newInterval[1] , intervals[i++][1]);
                ans.push_back({l, r});
                break;
            }
        }
        while (i < n)ans.push_back(intervals[i++]);
        return ans;
    }
};
