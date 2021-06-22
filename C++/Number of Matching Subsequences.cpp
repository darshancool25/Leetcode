// https://leetcode.com/problems/number-of-matching-subsequences/

/*Short Explanation -
It is not possible to check brutely if every word is a subseq of string s, because the length of s is too long.
Rather we traverse s and keep a track of how much prefix of each word is already seen (is a subseq).
The tuple<int,int,int> for a word denotes [index of word, prefix length which is a subseq, length of the word]
For example if the word is : "darshan" and tuple for it is : [2,3,7]
It denotes :
- words[2] = "darshan" [Index of word is 2 in original words vector].
- Of all the letters seen till now of s "dar" (prefix of length 3) is a subseq.
  Which also means the next character we are looking for is 's'.
  Hence [2,3,7] tuple will be present in mp['s'].
- Length of the word is 7.
  We store this because as soon as prefix length == length of word, it means the entire word is a subseq (we do ans++).
*/

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int i = 0, ans = 0;
        unordered_map <char, vector<tuple<int, int, int>>> mp;
        for (auto &word : words)
            mp[word[0]].push_back({i++, 0, word.length()});

        for (auto ch : s) {
            auto vect = mp[ch];
            mp[ch].clear();
            for (auto [id, pref, len] : vect) {
                if (++pref == len) ans++;
                else mp[words[id][pref]].push_back({id, pref, len});
            }
        }
        return ans;
    }
};
