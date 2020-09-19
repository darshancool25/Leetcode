// https://leetcode.com/problems/sequential-digits/

/*
Quick Explanation -
Generate all posssible numbers with sequential digits
in range [11,1e9]. Then just select the ones in the range
[low,high] and then return them.
*/

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector <int> all, ans;
        for (int i = 1; i <= 8; i++) {
            int num = i;
            for (int j = i + 1; j <= 9; j++) {
                if (num * 10 + j <= 1000000000) {
                    num = num * 10 + j;
                    all.push_back(num);
                }
            }
        }
        sort(all.begin() , all.end());
        auto it1 = lower_bound(all.begin() , all.end() , low);
        auto it2 = upper_bound(all.begin() , all.end() , high);
        while (it1 != it2)ans.push_back(*it1++);
        return ans;
    }
};
