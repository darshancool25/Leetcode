// https://leetcode.com/problems/powx-n/

class Solution {
public:
    double myPow(double x, int nn) {
        if (nn == 0) return 1.0;
        long long int n = nn;
        bool xneg, nneg, nodd = false;

        if (n & 1) nodd = true;        //odd power
        nneg = (n < 0) ? true : false; //power negative
        xneg = (x < 0) ? true : false; //base negative

        n = abs(n);
        x = abs(x);

        if (x == 1.0) { //base 1
            if (xneg) {
                if (n & 1) return (-1) * (1.0);
            }
            return (1.0);
        }

        double res = 1.0;
        while (n) {
            if (n & 1) res *= x;
            n >>= 1;
            x *= x;
        }

        if (nneg) res = 1.0 / res;
        if (xneg and nodd) res = -1 * res;
        return res;

    }
};
