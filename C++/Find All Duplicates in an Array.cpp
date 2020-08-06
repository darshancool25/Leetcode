// https://leetcode.com/problems/find-all-duplicates-in-an-array/


/*
Short Explaination -
IMP : all elements lie in [1,n]
mark the occurring elements by negating the
relevant position.
Now if that position if positive means, it has been negated twice!
*/
class Solution {
public:
	vector<int> findDuplicates(vector<int>& nums) {
		vector<int> ans;
		for (auto x : nums) {
			x = abs(x);
			nums[x - 1] *= -1;
			if (nums[x - 1] > 0)ans.push_back(x);
		}
		return ans;
	}
};