// https://leetcode.com/problems/repeated-substring-pattern/

/*Brute Solution - */
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        for (int i = 1; i <= n / 2; i++) {
            if (n % i)continue;
            bool ok = true;
            for (int j = 0; j < i; j++) {
                for (int k = 1; j + k * i < n; k++)ok &= (s[j] == s[j + k * i]);
            }
            if (ok)return ok;
        }
        return false;
    }
};

