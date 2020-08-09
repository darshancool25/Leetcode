// https://leetcode.com/problems/rotting-oranges/

/* Short Explaination - 
Maintain a queue to note the newly rottem orranges
in the last minute. Use it to find next set of rotten oranges.
If at end of process, fresh orange's exist, return -1
else return ans;
*/

#define f first
#define s second
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int h,w;
        h=grid.size();
        w = grid[0].size();
        set <pair<int,int>> fresh;
        queue <pair<int,int>> rot;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(grid[i][j]==0)continue;
                if(grid[i][j]==1)fresh.insert({i,j});
                if(grid[i][j]==2)rot.push({i,j});
            }
        }
        int ans=0;
        vector<pair<int,int>> dir{{1,0},{0,1},{-1,0},{0,-1}};
        while(!rot.empty()){
            int sz = rot.size();
            bool ok = false;
            while(sz--){
                pair<int,int> curr =  rot.front();
                rot.pop();
                for(auto x : dir){
                    if(fresh.find({curr.f+x.f,curr.s+x.s})!=fresh.end()){
                        fresh.erase({curr.f+x.f,curr.s+x.s});
                        rot.push({curr.f+x.f,curr.s+x.s});
                        ok = true;
                    }
                }                
            }
            if(!ok)break;
            else ans++;
        }
        if(!fresh.empty())return -1;
        return ans;        
    }
};
