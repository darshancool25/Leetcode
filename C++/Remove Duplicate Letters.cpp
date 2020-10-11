// https://leetcode.com/problems/remove-duplicate-letters/

/*Short Explanation -
Build the ans character by character(such that it lexicographically smallest). if the character
you are about to add to string is lower than ans.back(),and also there is another appearance of
ans.back() later in s, then you can pop_back() the character because you know you can add it later.
When you add a character to ans mark it vis = true, when you remove a character from ans mark
vis = false.
*/

class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map <char, int> mp;
        for (auto x : s)mp[x]++;
        unordered_map <char, bool> vis;
        string ans = "";
        for (auto x : s) {
            mp[x]--;
            if (vis[x])continue;
            while (ans.length() and ans.back() > x and mp[ans.back()]) {
                vis[ans.back()] = false;
                ans.pop_back();
            }
            ans += x;
            vis[x] = true;
        }
        return ans;
    }
};
