// https://leetcode.com/problems/remove-covered-intervals/

/*Short Explanation -
First we sort the given intervals in increasing order of starting points
[If any two intervals have same starting point, the one having bigger ending
point is placed first.] Now, We maintain a variable 'maxr', which stores the
maximum ending point till now, if for any interval say 'x', its ending point
is <= maxr , it means it is covered by some interval, as sorting ensures that
for the current interval 'x', x[0] >= earlier starting points.
*/

//O(n.log(n)) solution
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        auto cmpr = [&](vector<int> a, vector<int> b) {
            if (a[0] != b[0])return a[0] < b[0];
            else return a[1] > b[1];
        };
        sort(intervals.begin() , intervals.end() , cmpr);
        int maxr = -1, removed = 0;
        for (auto x : intervals) {
            if (x[1] <= maxr)removed++;
            else maxr = x[1];
        }
        return intervals.size() - removed;
    }
};