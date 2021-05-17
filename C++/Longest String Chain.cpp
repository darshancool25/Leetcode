// https://leetcode.com/problems/longest-string-chain/

/*Short Explanation -
Sort the words in increasing order of length.
If we know the length (mp[s]) of the longest word sequence that ends with a word 's'
we can use this value to find the length of the longest word sequence for its successor word 'curr'
For all possible 's' ('s' is basically string after dropping one letter from 'curr') :
mp[curr] = max(mp[curr] , mp[s] + 1)

Also because we are computing answers for words in increasing length, no case is missed.
*/

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int ans = 1;
        auto cmpr = [&](string a, string b) {
            return a.length() < b.length();
        };
        sort(words.begin() , words.end(), cmpr);
        map<string, int> mp;
        for (auto curr : words) {
            int n = curr.length();
            mp[curr] = 1;
            for (int i = 0; i < n; i++) {
                string s = "";
                for (int j = 0; j < n; j++) {
                    if (i == j)continue; //ith letter is dropped
                    s.push_back(curr[j]);
                }
                mp[curr] = max(mp[curr] , mp[s] + 1);
            }
            ans = max(ans, mp[curr]);
        }
        return ans;
    }
};
