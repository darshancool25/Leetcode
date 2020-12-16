// https://leetcode.com/problems/squares-of-a-sorted-array/

/*Lazy Solution - create a vector of squared elements, then sort it.
Time Complexity - O(n.log(n))*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res;
        for (auto x : nums)res.push_back(x * x);
        sort(res.begin() , res.end());
        return res;
    }
};

/*Better Solution -
Note - The given input array is sorted !
So we create 2 vectors : sq1, sq2. Both contain squares of negative, non-negative numbers respectively.
On reverseing sq1, both sq1 and sq2 contain sorted squared values.
Now we just need to merge these 2 vectors.
Time Complexity - O(n)
*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i = 0, j = 0, sz = nums.size();
        vector<int> sq1, sq2, ans;
        for (auto x : nums)
            (x < 0) ? sq1.push_back(x * x) : sq2.push_back(x * x);
        reverse(sq1.begin() , sq1.end());
        //now both sq1,sq2 are sorted. Now we just need to merge these 2 vectors
        while (i < sq1.size() and j < sq2.size())
            ans.push_back((sq1[i] < sq2[j] ? sq1[i++] : sq2[j++]));
        while (i < sq1.size())
            ans.push_back(sq1[i++]);
        while (j < sq2.size())
            ans.push_back(sq2[j++]);
        return ans;
    }
};
