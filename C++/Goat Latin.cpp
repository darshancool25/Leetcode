// https://leetcode.com/problems/goat-latin/

class Solution {
public:
    string toGoatLatin(string S) {
        map <char, int> mp;
        mp['a'] = 1; mp['A'] = 1;
        mp['e'] = 1; mp['E'] = 1;
        mp['i'] = 1; mp['I'] = 1;
        mp['o'] = 1; mp['O'] = 1;
        mp['u'] = 1; mp['U'] = 1;
        vector<string> vect;
        vect.push_back("");
        for (auto x : S) {
            if (x == ' ')vect.push_back("");
            else vect.back() += x;
        }
        for (int i = 0; i < vect.size(); i++) {
            if (mp[vect[i][0]]) {
                vect[i] += "ma";
            }
            else {
                reverse(vect[i].begin(), vect[i].end());
                reverse(vect[i].begin(), vect[i].end() - 1);
                vect[i] += "ma";
            }
            vect[i] += string(i + 1, 'a');
        }
        string ans = "";
        for (auto x : vect)ans += x + " ";
        ans.pop_back();
        return ans;
    }
};
