// https://leetcode.com/problems/reverse-integer/

/*Solution without using (long) or (long long)*/
class Solution {
public:
    int reverse(int x) {
        if (x == INT_MIN or x == 0)return 0;
        bool neg = x < 0;
        x = abs(x);
        int rev = 0;
        while (x > 0) {
            if (rev > INT_MAX / 10)return 0;
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        if (neg) return -rev;
        else return rev;
    }
};
