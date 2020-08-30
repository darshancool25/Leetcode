// https://leetcode.com/problems/largest-component-size-by-common-factor/

/*
Approach 1 - Using DFS
Create a undirected graph with edges between number and its prime factors.
the connected components will now contain all numbers sharing a common factor.
While counting size of connected component, include only the original elemnts in the given array.
*/

class Solution {
public:
    bool prime[100005];
    int spf[100005], cnt;
    vector<vector<int>> g;
    vector<bool> vis;
    map <int, int> mp;
    void sieve()
    {
        fill(prime, prime + 100005, true);
        for (int i = 1; i < 100005; i++)spf[i] = i;
        prime[0] = prime[1] = false;
        for (int i = 2; i * i < 100005; i++) {
            if (prime[i]) {
                for (int j = i * i; j < 100005; j += i) {
                    if (prime[j]) spf[j] = i;
                    prime[j] = false;
                }
            }
        }
    }
    vector<int> getFactorization(long long int x)
    {
        vector<int> ret;
        while (x != 1)
        {
            ret.push_back(spf[x]);
            x = x / spf[x];
        }
        return ret;
    }
    void dfs(int v) {
        if (mp[v])cnt++;
        vis[v] = true;
        for (auto u : g[v]) {
            if (!vis[u])dfs(u);
        }
    }
    int largestComponentSize(vector<int>& A) {
        g = vector<vector<int>>(100005);
        vis = vector<bool>(100005);
        sieve();
        for (auto x : A) {
            mp[x]++;
            vector<int> fact = getFactorization(x);
            for (auto y : fact) {
                g[x].push_back(y);
                g[y].push_back(x);
            }
        }
        int ans = -1;
        for (int i = 1; i < 100005; i++) {
            if (g[i].size() == 0)continue;
            if (!vis[i]) {
                cnt = 0;
                dfs(i);
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};
