// https://leetcode.com/problems/largest-time-for-given-digits/

/* Short Explanation - 
Check all possible permutations of 4 digits.
Find the valid and largest out of them!
*/
class Solution {
public:
    int value(vector<int> vect) {
        int val = 0;
        int hr = 0, min = 0;
        hr += vect[0] * 10 + vect[1];
        min += vect[2] * 10 + vect[3];
        return hr * 60 + min;
    }
    bool valid(vector<int> vect) {
        bool poss;
        poss = (vect[0] <= 2);
        if (vect[0] == 2) {
            poss &= (vect[1] >= 0 and vect[1] <= 3);
        }
        poss &= (vect[2] >= 0 and vect[2] <= 5);
        return poss;
    }
    string largestTimeFromDigits(vector<int>& A) {
        sort(A.begin(), A.end());
        vector<string> ans;
        bool poss = true;
        int max_time = -1;
        while (poss) {
            if (valid(A) and (value(A) > max_time)) {
                max_time = value(A);
                ans.clear();
                for (auto x : A)ans.push_back(to_string(x));
            }
            poss = next_permutation(A.begin() , A.end());
        }
        string time = "";
        if (max_time >= 0)
            time = ans[0] + ans[1] + ":" + ans[2] + ans[3];
        return time;
    }
};
