// https://leetcode.com/problems/car-pooling/

/*
Quick Explanation -
Create a timeline, that is at time 'i' pick[i]
number of people will be picked, and drop[i] number of
people will be dropped off.
If at any time the 'curr' exceeds capacity return false,
else return true.
*/

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> pick(1001, 0), drop(1001, 0);
        for (auto x : trips) {
            pick[x[1]] += x[0];
            drop[x[2]] += x[0];
        }
        int curr = 0;
        for (int i = 0; i <= 1000; i++) {
            curr += pick[i] - drop[i];
            if (curr > capacity)return false;
        }
        return true;
    }
};
