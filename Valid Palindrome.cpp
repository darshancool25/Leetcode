// https://leetcode.com/problems/valid-palindrome/

class Solution {
public:
	bool isPalindrome(string s) {
		string a, rev;
		for (auto x : s)if (isalnum(x))a += (tolower(x));
		rev = a;
		reverse(rev.begin(), rev.end());
		return a == rev;
	}
};