class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    vis[i][j]=1;
                  q.push({{i,j},0});
                }
            }
        }
        while(!q.empty()){
          int x = q.front().first.first;
          int y = q.front().first.second;
          int time = q.front().second;
          ans=max(ans,time);
          q.pop();
          int dr[] = {-1,1,0,0};
          int dc[] = {0,0,-1,1};
          for(int d=0;d<4;d++){
            int r = x+dr[d];
            int c = y+dc[d];
            if(r >=0 && r<n && c >=0 && c< m &&!vis[r][c] && grid[r][c]==1 ){
                vis[r][c]=1;
                grid[r][c]=2;
                q.push({{r,c},time+1});
            }
          }
        }
        for(int a=0;a<n;a++){
            for(int b=0;b<m;b++){
                if(grid[a][b]==1){
                    return -1;
                }
            }
        }
   return ans; }
};