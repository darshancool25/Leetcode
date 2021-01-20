// https://leetcode.com/problems/longest-palindromic-substring/

/*Short Explanation -
One can think to check all possible substrings and keep track of longest one.
This would require Time Complexity of O(n^3). [n^2 substrings, each requiring O(n) time to check if they are palindrome]

But notice that same can be done in O(n^2) by expanding palindromes around center. [That too in constant space]
Take each index 'i' as center and expand around it.

-> There are 2 types of palindrome :
1. odd length - center is 'i'
2. even length-  center is (i,i+1)

Lambdas used -
good(l,r) - returns if l,r lie in range [0,n-1]
len(pair<>) - returns length of <l,r> i.e  r - l + 1
expand(l,r) - expand around center considering l,r as center
*/

class Solution {
public:
    string longestPalindrome(string s) {
        int l, r, n = s.length();
        pair<int, int> ans{0, 0};
        auto good = [&](int l, int r) {return l >= 0 and l<n and r >= 0 and r < n;};
        auto len = [&](pair<int, int> a) {return a.second - a.first + 1;};
        auto expand = [&](int &l, int &r) {
            while (good(l, r) and s[l] == s[r]) {
                r++;
                l--;
            }
            return make_pair(++l, --r);
        };
        for (int i = 0; i < n; i++) {
            if (len(expand(l = i, r = i)) > len(ans))ans = {l, r};
            if (len(expand(l = i, r = i + 1)) > len(ans))ans = {l, r};
        }
        return s.substr(ans.first, len(ans));
    }
};
