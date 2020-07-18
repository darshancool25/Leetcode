// https://leetcode.com/problems/minimum-window-substring/

class Solution {
public:
    unordered_map<char,int> desired;
    unordered_map<char,int> curr;
    bool ok(){
        for(auto x : desired){
            if(curr[x.first] < x.second)return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        int l = 0, r = 0;
        int len = s.length();
        for(auto ch : t)desired[ch]++;
        int best = -1, wl=0,wr=0;
        while(r < len){
            curr[s[r]]++;
            while(ok() and l<=r){
                if(best==-1 or r-l+1 < best){
                    best = r-l+1;
                    wl = l;
                    wr = r;
                }
                curr[s[l]]--;
                l++;
            }
            r++;
        }
        if(best==-1)return "";
        return s.substr(wl,best);
    }
};
