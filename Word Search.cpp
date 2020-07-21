// https://leetcode.com/problems/word-search/

class Solution {
public:
    vector<vector<bool>> visited;
    int h,w;
    bool inside(int i, int j){
        return i>=0 and i<h and j>=0 and j<w;
    }
    vector<pair<int,int>>dir = {{0,1},{0,-1},{1,0},{-1,0}};
    
    bool dfs(vector<vector<char>>& board,string &word,int i, int j, int p){
        if(visited[i][j])return false;
        visited[i][j] = true;
        p++;
        if(p==word.length())return true;
        for(auto x : dir){
            int r = i+x.first, c = j+x.second;
            if(inside(r,c) and board[r][c]==word[p] and dfs(board,word,r,c,p))return true;
        }
        visited[i][j] = false;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        h = board.size();
        w = board[0].size();
        visited = vector<vector<bool>>(h,vector<bool>(w,false));
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(board[i][j] == word[0] and dfs(board,word,i,j,0))return true;
            }
        }
        return false;
    }
};
