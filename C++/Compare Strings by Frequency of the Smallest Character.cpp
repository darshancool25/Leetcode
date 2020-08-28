// https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character/

/*Brute Force Soln */
class Solution {
public:
    int func(string s) {
        map <char, int> mp;
        for (auto x : s)mp[x]++;
        return (*mp.begin()).second;
    }

    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> ans, w;
        for (auto x : words)w.push_back(func(x));
        for (auto x : queries) {
            int cnt = 0, q = func(x);
            for (auto y : w)cnt += (q < y);
            ans.push_back(cnt);
        }
        return ans;
    }
};
