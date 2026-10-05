class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int j=0;j<m ; j++){
            if(grid[0][j]==1){
                vis[0][j]=1;
                q.push({0,j});
            }
             if(grid[n-1][j]==1){
                vis[n-1][j]=1;
                q.push({n-1,j});
            }
        }
         for(int i=0;i<n ; i++){
            if(grid[i][0]==1){
                vis[i][0]=1;
                q.push({i,0});
            }
             if(grid[i][m-1]==1){
                vis[i][m-1]=1;
                q.push({i,m-1});
            }
        }
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            int dr[] = {-1,1,0,0};
            int dc[] = {0,0,-1,1};
            for(int d =0; d<4 ; d++){
                int r = x + dr[d];
                int c = y + dc[d];
                if(r>=0 && r<n && c>=0 && c<m && !vis[r][c] && grid[r][c]==1){
                    vis[r][c]=1;
                    q.push({r,c});
                }
            }
        }
        int ans = 0;
        for(int i =0 ;i<n ;i++){
            for(int j =0 ;j<m ;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    ans+=1;
                }
            }
        }
    return ans;}
};