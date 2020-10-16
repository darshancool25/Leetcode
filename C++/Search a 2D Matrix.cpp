// https://leetcode.com/problems/search-a-2d-matrix/

/*Short Explanation -
for each row , if target is within the range of first element
in the row and last element in the row, apply binary search on target
in that row.
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int h = matrix.size();
        if (h == 0)return false;
        int w = matrix[0].size();
        if (w == 0)return false;
        for (int i = 0; i < h; i++) {
            if (target >= matrix[i][0] and target <= matrix[i][w - 1])
                return *lower_bound(matrix[i].begin() , matrix[i].end() , target) == target;
        }
        return false;
    }
};
