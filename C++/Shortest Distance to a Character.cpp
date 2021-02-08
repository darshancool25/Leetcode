// https://leetcode.com/problems/shortest-distance-to-a-character/

/*Approach 1 - Store all positions of c in a vector. [Pad the vector with large -ve and +ve numbers on ends]
and for each index i in [0,n-1] we find closest index of c present to its left
and similarly to its right, they are stored in 'l' and 'r' respectively
ans[i] = min(r - i, i - l)
Note : This approach requires O(N) time, O(N) space [to store all positions of c]
*/
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.length();
        vector<int> ans(n, -1), posn{ -100000};
        for (int i = 0; i < n; i++) {
            if (s[i] == c) {
                ans[i] = 0;
                posn.push_back(i);
            }
        }
        posn.push_back(100000);
        if (posn.size() == n + 2)return ans;
        int l_i = 0, r_i = 1, l = posn[0], r = posn[1];
        for (int i = 0; i < n; i++) {
            if (i == posn[r_i]) {
                l_i++; r_i++;
                r = posn[r_i]; l = posn[l_i];
            }
            if (ans[i] == 0)continue;
            ans[i] =  min(r - i, i - l);
        }
        return ans;
    }
};

/*Approach 2 -
Iterate twice in the string : left to right and vice versa
We can keep track of last known position of char c using O(1) space,
say in variable 'last'.
While going from left to right ans[i] = i - last
While going from right to left ans[i] = last - i
Hence we store the minimum of both.
Also initially the ans vector is initialised to n, because we are sure
no ans[i] can ever be >= n

Note : this approach also takes O(N) time and space [for storing answer vector],
but the additional space of storing all positions of char c is not required here
making the solution slightly efficient than Approach 1
*/

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int last = -1, n = s.length();
        vector<int> ans(n, n);
        for (int i = 0; i < n; i++) {
            if (s[i] == c)last = i;
            if (last == -1)continue;
            ans[i] = i - last;
        }
        last = n;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == c)last = i;
            if (last == n)continue;
            ans[i] = min(ans[i] , last - i);
        }
        return ans;
    }
};
