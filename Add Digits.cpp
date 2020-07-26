// https://leetcode.com/problems/add-digits/

/*Recursive Solution*/
class Solution {
public:
    int addDigits(int num) {
        int sum=0;
        while(num>0){
            sum += num%10;
            num/=10;
        }
        if(sum>=0 and sum<=9)return sum;
        else return addDigits(sum);
    }
};

/*O(1) Solution*/
class Solution {
public:
    int addDigits(int num) {
        if(num==0)return 0;
        if(num%9==0)return 9;
        return num%9;
    }
};
