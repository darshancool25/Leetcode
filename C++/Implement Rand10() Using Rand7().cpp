// https://leetcode.com/problems/implement-rand10-using-rand7/

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        /*to decide whether your answer is going to be in 1-5 or 6-10 we chose
         a random number 'x' in 1-6 using rand7() and will later use its parity*/
        int x = rand7();
        while (x == 7)x = rand7();

        /*Now chose a random number in 1-5 using rand7()*/
        int base = rand7();
        while (base > 5)base = rand7();

        /*return answer based on parity of x*/
        return base + (x % 2) * 5;
    }
};
