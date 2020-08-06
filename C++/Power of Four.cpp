// https://leetcode.com/problems/power-of-four/

/*
Short Explaination - If number of set bits in num are 1, and least significant bit
is on a odd position, num is a power of 4.
*/

class Solution {
public:
    bool isPowerOfFour(int num) {
        return (__builtin_popcount(num) == 1 and ffs(num) & 1);
    }
};
