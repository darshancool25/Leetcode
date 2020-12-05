// https://leetcode.com/problems/can-place-flowers/

/*Short Explanation -
Compress given flowerbed in pairs of <1/0 , cnt>.
now for 0's present at end or beginning cnt/2 plants can be planted.
For rest 0's groups atleast 3 0's should be present. then (cnt-1)/2 number of plants can be planted.

Corner case (To be handled separetly): the flowerbed consists of only zeroes.
(cnt+1)/2 plants can be planted.
*/

class Solution {
public:
    void CompressArray(vector<int>&arr, vector<pair<int, int>>&res) {
        for (int i = 0; i < arr.size(); i++) {
            if (res.size() == 0) res.push_back(make_pair(arr[i], 1));
            else {
                if (arr[i] == res[res.size() - 1].first) res[res.size() - 1].second++;
                else res.push_back(make_pair(arr[i], 1));
            }
        }
    }
    bool canPlaceFlowers(vector<int>& arr, int n) {
        vector<pair<int, int>> res;
        CompressArray(arr, res);
        int tot = 0, sz = res.size();
        if (sz == 1 and arr[0] == 0) { //corner case
            tot += (res[0].second + 1) / 2;
            return tot >= n;
        }
        for (int i = 0; i < sz; i++) {
            if (res[i].first == 1)continue;
            if (i == 0 or i == sz - 1)tot += res[i].second / 2;
            else tot += (res[i].second - 2 > 0 ? (res[i].second - 1) / 2 : 0);
        }
        return tot >= n;
    }
};
