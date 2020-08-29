// https://leetcode.com/problems/pancake-sorting/

/*Short Explanation -
One by one bring in descending order of values bring element
to index 0 and then to its actual position in the sorted array.
*/
class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> ans;
        int sz = A.size();
        for (int i = 0; i < sz; i++) {
            auto it = max_element(A.begin() , A.end() - i);
            ans.push_back(it - A.begin() + 1);
            reverse(A.begin() , A.begin() + ans.back());
            ans.push_back(sz - i);
            reverse(A.begin() , A.begin() + ans.back());
        }
        return ans;
    }
};
