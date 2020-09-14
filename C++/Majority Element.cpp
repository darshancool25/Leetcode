// https://leetcode.com/problems/majority-element/

//O(n) solution
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele = nums[0], cnt = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == ele)cnt++;
            else cnt--;
            if (cnt == 0) {
                ele = nums[i];
                cnt = 1;
            }
        }
        return ele;
    }
};

//O(n.log(n)) solution
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        return nums[nums.size() / 2];
    }
};

//using map to store freq of each element
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map <int, int> mp;
        for (int i = 0; i < nums.size(); i++)mp[nums[i]]++;
        int ans;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            if ((*it).second > nums.size() / 2)ans = (*it).first;
        }
        return ans;
    }
};
