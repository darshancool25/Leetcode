// https://leetcode.com/problems/word-pattern/

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> words;
        string s = "";
        for (char x : str) {
            if (x == ' ') {
                words.push_back(s);
                s = "";
            }
            else s.push_back(x);
        }
        if (s != "")words.push_back(s);
        if (pattern.length() != words.size())return false;
        unordered_map <char , set<string>> mp;
        for (int i = 0; i < pattern.length() ; i++) {
            mp[pattern[i]].insert(words[i]);
            if (mp[pattern[i]].size() > 1)return false;
        }
        set <string> st;
        for (auto x : mp)
            st.insert(*((x.second).begin()));
        if (st.size() < mp.size())return false;
        return true;
    }
};
