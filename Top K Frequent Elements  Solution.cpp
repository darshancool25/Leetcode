// https://leetcode.com/problems/top-k-frequent-elements/

//Soln using Boolean Comparator
class Solution {
public:   
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int,int> mp;
        for(auto x : nums)mp[x]++;
        vector<pair<int,int>> vect;
        for(auto x : mp)vect.push_back(x);
        auto cmpr = [&](pair<int,int> a, pair<int,int> b){
            return a.second >= b.second;
        };
        sort(vect.begin(),vect.end(),cmpr); //sort by frequency in descending order
        vector<int>ans;
        for(int i=0;i<k;i++)ans.push_back(vect[i].first);
        return ans;
    }
};


//Soln using MultiMap : 
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        for(auto x : nums)mp[x]++;
        multimap <int,int,greater<int>> mmp;
        for(auto x : mp)mmp.insert({x.second,x.first});
        vector<int> ans;
        for(auto x : mmp){
            ans.push_back(x.second);
            if(ans.size()==k)break;
        }
        return ans;
    }
};
