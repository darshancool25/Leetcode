// https://leetcode.com/problems/excel-sheet-column-number/

class Solution {
public:
	int titleToNumber(string s) {
		int ans = 0, len = s.length();
		for (int i = len - 1; i >= 0; i--) {
			if (i == len - 1)ans += s[i] - 'A' + 1;
			else {
				ans += (s[i] - 'A' + 1) * pow(26, len - i - 1);
			}
		}
		return ans;
	}
};