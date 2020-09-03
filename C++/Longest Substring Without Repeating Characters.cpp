// https://leetcode.com/problems/longest-substring-without-repeating-characters/

/*
Short Explanation -
Create a window with l=0,r=0,
increase window size if possible,
decrease window size by increasing l, while mp[s[r]]>1
update ans at each good window
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int l = 0, r = 0 , ans = 0;
        while (r < s.length() and l <= r) {
            mp[s[r]]++;
            while (mp[s[r]] > 1)mp[s[l++]]--;
            ans = max(ans , r - l + 1);
            r++;
        }
        return ans;
    }
};
