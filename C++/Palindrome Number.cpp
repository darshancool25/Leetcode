// https://leetcode.com/problems/palindrome-number/

/*Solution without converting number to string*/
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)return false;
        long rev = 0, num = x;
        while (num > 0) {
            rev = rev * 10 + num % 10;
            num /= 10;
        }
        return rev == x;
    }
};

/*Solution by converting number to string*/
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        string num, rev;
        rev = num = to_string(x);
        reverse(rev.begin() , rev.end());
        return rev == num;
    }
};
