// https://leetcode.com/problems/combination-sum/

/*Quick Explanation -
IMPORTANT : 'candidates' consists of distinct integers.
(If it wasnt distinct , we would have to make it array of distinct integers).
Now recursively we calculate the total combinations by either
1. including a particular number (reducing the target at same time).
2. excluding the number (target remains same, but index is incremented).

NOTE :
target<0 or index >candidates.size() are non-favourable cases,
so in case they occur just return.
*/

class Solution {
public:

    vector<vector<int>> ans;
    vector<int> curr;
    void recurse(vector<int>& candidates, int target, int index) {
        if (target == 0)ans.push_back(curr);
        if (target<0 or index >= candidates.size())return;
        curr.push_back(candidates[index]);
        recurse(candidates, target - curr.back() , index);
        curr.pop_back();
        recurse(candidates, target, index + 1);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        recurse(candidates, target, 0);
        return ans;
    }
};
