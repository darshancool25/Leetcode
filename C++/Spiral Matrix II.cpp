// https://leetcode.com/problems/spiral-matrix-ii/

/*Short Explanation -
'dir' contains the directions in order. We follow these directions in cyclic order.
start with pt{0,0}, d=0 and fill the number and change 'pt' to next point in direction dir[d].
if the point you are going to is already visited OR out of bounds, (d++)%4.

Basically the process simulates the filling of the matrix in spiral order from 1 to n*n.
*/

#define f first
#define s second
class Solution {
public:
    vector<pair<int, int>> dir{{0, 1}, {1, 0}, {0, -1}, { -1, 0}};
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int num = 1, d = 0;
        pair<int, int> pt{0, 0}, temp;
        auto next = [&](pair<int, int> &a) {
            temp.f = a.f + dir[d].f; temp.s = a.s + dir[d].s;
            if (!(temp.f >= 0 and temp.s >= 0 and temp.f < n and temp.s < n and ans[temp.f][temp.s] == 0))
                d = (d + 1) % 4;
            a.f = a.f + dir[d].f; a.s = a.s + dir[d].s;
        };
        while (num <= n * n) {
            ans[pt.f][pt.s] = num++;
            next(pt);
        }
        return ans;
    }
};
