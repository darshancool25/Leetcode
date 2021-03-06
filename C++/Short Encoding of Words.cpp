// https://leetcode.com/problems/short-encoding-of-words/

/*
Short Explanation -
First of all sorting the strings in descending order of length is necessary,
because a smaller string, say "ime" can only be suffix of a larger string, say "time".
Once sorted, we create an empty set 'st'.
Now for each string, we check if that string is present in our set.
If yes, we just continue. for eg : "ime" is already a part of "time".
But if the string is not present in the set, we add the string and its all possible suffixes in the set.
eg- if string is - "time" and set does not contain it.
We insert {"time" , "ime" , "me" , "e"} in the set.

Every time we insert a new string and its suffixes in the set, our Encoded string length
increases by len+1 , where len is length of string we are inserting ex len("time") = 4
so encoded string would contain - time#
*/

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        auto cmpr = [&](string a, string b) {
            return a.length() > b.length();
        };
        sort(words.begin() , words.end() , cmpr);
        set<string> st;
        int ans = 0;
        for (auto curr : words) {
            if (st.find(curr) != st.end())continue;
            int len = curr.length();
            ans += len + 1;
            for (int i = 0; i < len; i++)
                st.insert(curr.substr(i, len - i));
        }
        return ans;
    }
};
