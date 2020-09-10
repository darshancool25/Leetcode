// https://leetcode.com/problems/bulls-and-cows/

class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map <char, int> s, g;
        for (auto x : secret)s[x]++;
        for (auto x : guess)g[x]++;
        int cows = 0, bulls = 0;
        for (auto x : s) {
            cows += min(x.second , g[x.first]);
        }
        for (int i = 0; i < secret.length(); i++)
            if (secret[i] == guess[i])bulls++;
        cows -= bulls;
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
