// https://leetcode.com/problems/task-scheduler/

class Solution {
public:
	int leastInterval(vector<char>& tasks, int n) {
		map <char, int> mp;
		for (auto x : tasks)mp[x]++;
		int cnt = 0, maxx = -1;
		for (auto x : mp)maxx = max(maxx, x.second);
		for (auto x : mp)if (x.second == maxx)cnt++;
		return max((int)tasks.size() , (maxx - 1) * (n + 1) + cnt);
	}
};