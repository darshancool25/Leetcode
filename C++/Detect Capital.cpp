// https://leetcode.com/problems/detect-capital/

class Solution {
public:
    bool detectCapitalUse(string word) {
        int len = word.length();
        int cnt = 0;
        for (auto x : word)if (x >= 'A' and x <= 'Z')cnt++;
        if (cnt == 0 or cnt == len)return true;
        else if (cnt == 1 and word[0] >= 'A' and word[0] <= 'Z')return true;
        return false;
    }
};
