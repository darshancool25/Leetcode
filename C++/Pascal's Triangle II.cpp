// https://leetcode.com/problems/pascals-triangle-ii/

/*Solution Using extra space, build each row and return required row - */
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector <vector<int>> pascal(rowIndex + 1);
        pascal[0] = vector<int> {1};
        for (int i = 1; i <= rowIndex; i++) {
            pascal[i].push_back(1);
            for (int j = 1; j < pascal[i - 1].size(); j++) {
                pascal[i].push_back(pascal[i - 1][j] + pascal[i - 1][j - 1]);
            }
            pascal[i].push_back(1);
        }
        return pascal[rowIndex];
    }
};

/*Follow up : Using only O(k) extra space - */
