// https://leetcode.com/problems/compare-version-numbers/

class Solution {
public:
    vector<string> split(string str) {
        vector<string> res;
        string s = "";
        for (char x : str) {
            if (x == '.') {
                res.push_back(s);
                s = "";
            }
            else s.push_back(x);
        }
        res.push_back(s);
        return res;
    }
    int compareVersion(string version1, string version2) {
        vector<string> v1, v2;
        v1 = split(version1);
        v2 = split(version2);
        int l1 = v1.size(), l2 = v2.size();
        while (v1.size() < max(l1, l2))v1.push_back("0");
        while (v2.size() < max(l1, l2))v2.push_back("0");
        for (int i = 0; i < max(l1, l2); i++) {
            if (stoi(v1[i]) > stoi(v2[i]))return 1;
            else if (stoi(v1[i]) < stoi(v2[i]))return -1;
        }
        return 0;
    }
};
