// https://leetcode.com/problems/2-keys-keyboard/

class Solution {
public:
    int minSteps(int n) {
        //prime factorization
        int ans = 0,d=2;
        while(n>1){
            while(n%d==0){
                n/=d;
                ans+=d;
            }
            d++;
        }
        return ans;        
    }
};
