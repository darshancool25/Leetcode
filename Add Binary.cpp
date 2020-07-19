// https://leetcode.com/problems/add-binary/

class Solution {
public:
    string addBinary(string a, string b) {
        int len = max(a.length(),b.length());
        //make a and b of equal length
        a = string(len-a.length(),'0') + a;
        b = string(len-b.length(),'0') + b;
        string ans;
        bool carry = false;
        for(int i=len-1;i>=0;i--){
            int sum=0;
            sum += a[i]-'0';
            sum += b[i]-'0';
            if(!carry){
                if(sum==2){
                    ans += '0';
                    carry = true;
                    continue;
                }
                else ans += sum + '0';                
            }
            if(carry){
                if(sum==0){
                    carry = false;
                    ans += '1';
                }
                else if(sum==1) ans += '0';
                else ans += '1';
            }
        }
        if(carry)ans +='1';
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
