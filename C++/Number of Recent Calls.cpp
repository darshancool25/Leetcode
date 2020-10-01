// https://leetcode.com/problems/number-of-recent-calls/

/*Quick Explanation -
As each ping t will be strictly greater than previous one,
the required number in [t-3000,t] can be found by counting
number of elements present in [lower_bound(t-3000) , vect.end() )
*/

class RecentCounter {
public:
    vector <int> vect;
    RecentCounter() {

    }

    int ping(int t) {
        vect.push_back(t);
        return vect.end() - lower_bound(vect.begin() , vect.end() , t - 3000);
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
