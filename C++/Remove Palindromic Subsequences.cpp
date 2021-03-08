// https://leetcode.com/problems/remove-palindromic-subsequences/

/*Short Explanation -
If string is empty ans is ofcourse 0.
If the entire string is a palindrome, answer is 1.
Else the answer is 2, because string consists of only 2 letters,
i.e 'a' and 'b'. In one move we can remove all a's and in second all b's.
*/

class Solution {
public:
    int removePalindromeSub(string s) {
        if (s == "")return 0;
        string t = s;
        reverse(t.begin() , t.end());
        if (s == t)return 1;
        else return 2;
    }
};
