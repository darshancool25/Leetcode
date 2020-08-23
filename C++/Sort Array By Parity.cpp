// https://leetcode.com/problems/sort-array-by-parity/

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> even, odd;
        for (auto x : A)
            (x & 1 ? odd.push_back(x) : even.push_back(x));
        for (auto x : odd)even.push_back(x);
        return even;
    }
};
