// https://leetcode.com/problems/single-number-iii/


/*
Short Explaination : 
1. Find XOR of all elements, let it be 'xorr'
2. xorr has atleast one set bit , meaning that the two numbers to be found differ at that particular bit.
3. Partition whole array into two partitions, on basis of that particular bit.
4. Above step ensures that the desired numbers are in two different partitions.
4. XOR of these two partitions are the two desired numbers.
*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans;
        int a=0,b=0,xorr=0;
        for(auto x : nums)xorr ^= x;
        int set_bit = (xorr & ~(xorr-1));
        for(auto x : nums){
            if(x & set_bit)a^=x;
            else b^=x;
        }
        ans.push_back(a);
        ans.push_back(b);
        return ans;
    }
};
