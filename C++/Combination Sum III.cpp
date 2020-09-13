// https://leetcode.com/problems/combination-sum-iii/

/*
Quick Explanation -
Try all possible combinations with help of binary strings of length 10,
containing k '1's.
*/
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        for (int i = 1; i < 1024; i += 2) {
            int cnt = 0;
            vector<int> num;
            for (int j = 1; j <= 9; j++) {
                if (1 & (i >> j))num.push_back(j);
            }
            if (num.size() != k)continue;
            if (accumulate(num.begin() , num.end(), 0) == n)ans.push_back(num);
        }
        return ans;
    }
};
