https://leetcode.com/problems/angle-between-hands-of-a-clock/

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hr=0,mn=0;
        if(hour==12)hour=0;
        hr += ((double)hour)*(30.0) + ((double)minutes)*(0.5);
        mn += ((double)minutes)*(6.0);
        double ans = abs(hr-mn);
        ans = min(ans,360.0-ans);
        return ans;       
    }
};
