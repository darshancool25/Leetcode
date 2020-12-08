// https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/

/* Short Explanation -
Each number has some remainder when divided by 60, i.e num % 60.
Sum of two numbers say num1, num2 is a multiple of 60 if (num1%60 + num2%60) is divisible by 60.
So we create a frequency array 'cnt' of size 60,
where cnt[i] denotes frequency of numbers having (num % 60 == i)
Now ans = (cnt[1]*cnt[59]) + (cnt[2]*cnt[58]).....(cnt[29]*cnt[31])
also
ans += (cnt[0] * (cnt[0] - 1)) / 2;       i.e nCr(cnt[0], 2)
ans += (cnt[30] * (cnt[30] - 1)) / 2;     i.e nCr(cnt[30],2)

*/

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> cnt(60, 0);
        for (auto x : time)cnt[x % 60]++;
        int ans = 0, l = 1, r = 59;
        while (l < r)ans += cnt[l++] * cnt[r--];
        ans += (cnt[0] * (cnt[0] - 1)) / 2;
        ans += (cnt[30] * (cnt[30] - 1)) / 2;
        return ans;
    }
};
