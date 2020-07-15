// https://leetcode.com/problems/reverse-words-in-a-string/

class Solution {
public:
    string reverseWords(string s) {
        bool empty = true;
        for(auto x : s){
            if(x !=' '){
                empty = false;
                break;
            }
        }
        if(empty)return "";
        istringstream ss(s);
        string ans = "";
        vector<string> vect;
        do{
            string temp;
            ss >> temp;
            vect.push_back(temp);
        }while(ss);
        vect.pop_back(); //last element of vect is an empty string
        while(vect.size()){
            ans += vect.back() + " ";
            vect.pop_back();
        }
        ans.pop_back(); //removes the last space in ans string
        return ans;
    }
};
