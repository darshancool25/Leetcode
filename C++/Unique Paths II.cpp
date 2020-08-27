// https://leetcode.com/problems/unique-paths-ii/

/*Dynamic Programming Solution*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0] == 1)return 0;
        int h, w;
        h = obstacleGrid.size();
        w = obstacleGrid[0].size();
        int dp[h][w];
        auto inside = [&](int r, int c) {
            return (r >= 0 and c >= 0 and r < h and c < w);
        };
        auto obstacle = [&](int r, int c) {
            return obstacleGrid[r][c] == 1;
        };
        dp[0][0] = 1;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (!(i == 0 and j == 0))dp[i][j] = 0;
                if (obstacle(i, j))continue;
                if (inside(i - 1, j))dp[i][j] += dp[i - 1][j];
                if (inside(i, j - 1))dp[i][j] += dp[i][j - 1];
            }
        }
        return dp[h - 1][w - 1];
    }
};
