// https://leetcode.com/problems/longest-common-prefix/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)return "";
        for(auto &x : strs)reverse(x.begin(),x.end());
        int sz = strs.size();
        string ans;
        while(true){
            int cnt = 0;
            for(auto x : strs)if(x.length()>0)cnt++;
            if(cnt<sz)break;
            char ch;
            ch = strs[0].back();
            bool done = false;
            for(auto &x : strs){
                if(x.back()==ch)x.pop_back();
                else {
                    done = true;
                    break;
                }
            }
            if(done)break;
            ans += ch;
        }
        return ans;
    }
};

//alternate fast solution
class Solution{
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)return "";
        for(int i=0;i<strs[0].length();i++){
            char ch = strs[0][i];
            for(int j=1;j<strs.size();j++){
                if(strs[j].length()==i or strs[j][i]!=ch)
                    return strs[0].substr(0,i);
            }            
        }
        return strs[0];
    }    
};
