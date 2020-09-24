// https://leetcode.com/problems/find-the-difference/

class Solution {
public:
    char findTheDifference(string s, string t) {
        map <char, int> mp;
        for (auto x : t)mp[x]++;
        for (auto x : s)mp[x]--;
        char ans;
        for (auto x : mp) {
            if (x.second > 0)ans = x.first;
        }
        return ans;
    }
};
