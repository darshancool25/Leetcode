// https://leetcode.com/problems/sqrtx/

/*Binary Search on Answer*/
class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) {
            return x;
        }
        int low = 0;
        int high = x;
        int mid;
        while (low <= high) {
            mid = (low + high) / 2;
            if ( (mid <= x / mid) && ( (mid + 1) > ( x / (mid + 1) ) ) ) {
                break;
            }
            else if (mid < x / mid) {
                low = mid + 1;
            }
            else if (mid > x / mid) {
                high = mid - 1;
            }
        }
        return mid;
    }
};
