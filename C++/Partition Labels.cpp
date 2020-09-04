// https://leetcode.com/problems/partition-labels/


/*
Quick Explanation -
Greedily choose smallest partition for the first letter,i.e l=0
for all elements in that partition, if someones last index, i.e mp[S[i]]
is greater than r, update r
After each iteration : l = r+1
*/
class Solution {
public:
    vector<int> partitionLabels(string S) {
        unordered_map <char, int> mp;
        int l = 0, r = 0, n = S.length();
        for (int i = 0; i < n; i++)mp[S[i]] = i;
        vector<int> ans;
        while (l < n) {
            r = mp[S[l]];
            for (int i = l; i < r; i++) {
                if (mp[S[i]] > r)r = mp[S[i]];
            }
            ans.push_back(r - l + 1);
            l = r + 1;
        }
        return ans;
    }
};
