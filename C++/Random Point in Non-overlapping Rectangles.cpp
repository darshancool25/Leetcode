// https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/

class Solution {
public:
    vector<vector<int>> rects;
    vector<int> vect;
    Solution(vector<vector<int>>& rects) {
        this->rects = rects;
        int total_area = 0;
        auto area = [&](vector<int> pt) {
            return (pt[2] - pt[0] + 1) * (pt[3] - pt[1] + 1);
        };
        for (auto rect : rects) {
            total_area += area(rect);
            vect.push_back(total_area);
        }
        srand(time(0));
    }
    vector<int> pick() {
        int area = rand() % vect.back();
        int i = upper_bound(vect.begin(), vect.end(), area) - vect.begin();
        vector<int> pt(2);
        pt[0] = rects[i][0] + (rand() % (rects[i][2] - rects[i][0] + 1));
        pt[1] = rects[i][1] + (rand() % (rects[i][3] - rects[i][1] + 1));
        return pt;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
