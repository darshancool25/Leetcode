// https://leetcode.com/problems/image-overlap/

/*Brute Force Solution - Constant Space*/
class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size() , ans = 0;
        auto good = [&](int r, int c) {
            return r >= 0 and r<n and c >= 0 and c < n;
        };
        for (int hor = -(n - 1); hor < n; hor++) {
            for (int ver = -(n - 1); ver < n; ver++) {
                int cnt = 0;
                for (int i = 0; i < n; i++)
                    for (int j = 0; j < n; j++)
                        if (good(i + ver , j + hor))
                            cnt += (A[i][j] == 1) and (A[i][j] == B[(i + ver)][(j + hor)]);
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};
