// https://leetcode.com/problems/course-schedule-ii/

/*
Quick Explaination : Answer is equivalent to finding topological ordering in directed graph.
But if there exists a cycle in the graph the answer is not possible so we return a empty vector.
*/

class Solution {
public:
    vector<vector<int>> g;
    vector<int> topo;
    enum colour {white, grey, black};
    vector<colour> col;
    bool cycle = false;
    void dfs(int v) {
        col[v] = grey;
        for (auto u : g[v]) {
            if (col[u] == grey)cycle = true;
            if (col[u] == white)dfs(u);
        }
        col[v] = black;
        topo.push_back(v);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        g = vector<vector<int>>(numCourses);
        col = vector<colour>(numCourses);
        for (auto x : prerequisites) {
            g[x[1]].push_back(x[0]);
        }
        for (int i = 0; i < numCourses; i++) {
            if (col[i] == white)dfs(i);
        }
        if (cycle)return vector<int>();
        reverse(topo.begin(), topo.end());
        return topo;

    }
};
