// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

/*Short Explanation -
This question is same as Process/Activity Scheduling Problem.
i.e Given some processes what is the maximum number of process you can
schedule such that they dont overlap.
SOLN - Sort by end point, maintain a current_end point (initially -INF).
Now iterate in vector, for a interval if its starting point is greater than curr_end
point, we can schedule that interval/process. So ans++ and also update the curr_end.
*/

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        auto cmpr = [&](vector<int> &a, vector <int> &b) {
            return a[1] < b[1];
        };
        sort(points.begin() , points.end() , cmpr);
        long ans = 0, curr_end = LONG_MIN;
        for (auto x : points) {
            if (x[0] > curr_end) {
                ans++;
                curr_end = x[1];
            }
        }
        return ans;
    }
};

/* C++ Users note that if you dont pass arguments to cmpr by reference
   it may give TLE
*/
