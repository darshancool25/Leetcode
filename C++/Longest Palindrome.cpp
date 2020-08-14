// https://leetcode.com/problems/longest-palindrome/

/*
Short Explaination - 
Include all characters who occur even no. of times.
but for odd include (freq-1) of each char.
Finally you can(if possible) include one character odd many times!
*/

#define s second
class Solution {
public:
    int longestPalindrome(string str) {
        unordered_map <char,int> mp;
        for(auto ch : str)mp[ch]++;
        int ans = 0,odd=0;
        for(auto x : mp){
            if(x.s%2==0)ans += x.s;
            else{
                ans += x.s-1;
                odd++;
            }
        }
        if(odd)ans++;
        return ans;
    }
};
