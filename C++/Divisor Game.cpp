// https://leetcode.com/problems/divisor-game/

/*Intuition and Observation*/
class Solution {
public:
    bool divisorGame(int N) {
        return !(N % 2);
    }
};

/*Dynamic Prgramming Solution*/
class Solution {
public:
    bool divisorGame(int N) {
        vector<bool> dp(3);
        dp[0] = dp[1] = false;
        dp[2] = true;
        for (int i = 3; i <= N; i++) {
            bool poss = false;
            for (int j = 1; j < i; j++) {
                if (i % j == 0)poss |= !(dp[i - j]);
            }
            dp.push_back(poss);
        }
        return dp[N];
    }
};
