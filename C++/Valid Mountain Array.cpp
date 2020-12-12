// https://leetcode.com/problems/valid-mountain-array/

/*Short Explanation -
First while loop is for sequence of increasing elements,
second while loop is for sequence of decreasing elements.
Code must enter both while loops and end at i==n-1.
In all other cases answer is 'false'.
*/

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int i = 1, n = arr.size(), last = arr[0];
        if (n < 3)return false;
        bool good = false;
        while (i<n and arr[i] > last) {
            last = arr[i++];
            good = true;
        }
        while (i < n and arr[i] < last) {
            if (good and i == n - 1)return true;
            last = arr[i++];
        }
        return false;
    }
};
