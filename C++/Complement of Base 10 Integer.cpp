// https://leetcode.com/problems/complement-of-base-10-integer/

class Solution {
public:
    int bitwiseComplement(int N) {
        string bin = "";
        if (N == 0)bin = "0";
        while (N > 0) {
            bin += to_string(N % 2);
            N /= 2;
        }
        for (auto &x : bin)
            x = (x == '1' ? '0' : '1');
        int ans = 0, i = 0;
        for (auto x : bin) {
            ans += (x == '1' ? 1 << i : 0);
            i++;
        }
        return ans;
    }
};