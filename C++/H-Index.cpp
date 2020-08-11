// https://leetcode.com/problems/h-index/

/*
Short Explaination : 
Possible Values of H-index can be [0,N],
where N is the number of published papers.
Sort the given vector and do 'Binary Search on Answer'.
*/

class Solution {
public:
    int count(vector<int>& citations, int mid){
        int cnt = 0;
        for(auto x : citations)cnt += (x>=mid);
        return cnt;
    }
    
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int low = 0, high = citations.size();
        int ans = 0;
        while(low<=high){
            int mid = (low + high)/2;
            int cnt = count(citations,mid);
            if(cnt>=mid){
                low = mid+1;
                ans = mid;
            }
            else high = mid-1;
        }
        return ans;
    }
};
