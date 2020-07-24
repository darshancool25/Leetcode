// https://leetcode.com/problems/all-paths-from-source-to-target/

class Solution {
public:
    vector<bool> visited;
    vector<vector<int>> ans;
    vector<int>path;
    int des;
    void dfs(vector<vector<int>>& g,int v){
        visited[v] = true;
        path.push_back(v);
        if(v==des){
            ans.push_back(path);
        }
        else{
            for(auto u : g[v]){
                if(!visited[u])dfs(g,u);
            }
        }     
        path.pop_back();
        visited[v] = false;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        des = n-1;
        visited = vector<bool>(n,false);
        dfs(graph,0);
        return ans;
    }
};
