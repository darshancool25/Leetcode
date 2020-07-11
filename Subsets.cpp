class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int total,sz = nums.size();
        total = 1<<sz;
        for(int i=0;i<total;i++){
            vector<int> temp;
            for(int j=0;j<sz;j++){
                if(i & (1<<j))temp.push_back(nums[j]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
