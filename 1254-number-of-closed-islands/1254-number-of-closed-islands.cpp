class Solution {
public:

   void dfs(int i,int j,vector<vector<int>> &vis,vector<vector<int>> &grid ){
    int n = grid.size();
    int m = grid[0].size();
    vis[i][j]=1;
    grid[i][j]=1;
    int dr[]={-1,1,0,0};
    int dc[]={0,0,-1,1};
    for(int d=0;d<4;d++){
        int r = i + dr[d];
        int c = j+dc[d];
        if(r>=0 && r<n && c<m && c>=0 && !vis[r][c] && grid[r][c]==0){
            dfs(r,c,vis,grid);
        }
    }
   }
   int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i =0;i<n;i++){
            if(grid[i][0]==0)
            dfs(i,0,vis,grid);
            if(grid[i][m-1]==0)
            dfs(i,m-1,vis,grid);
        }
        for(int j=0;j<m;j++){
            if(grid[0][j]==0)
            dfs(0,j,vis,grid);
            if(grid[n-1][j]==0)
            dfs(n-1,j,vis,grid);
        }
        int ans = 0 ;
       
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==0){
                    ans++;
                    dfs(i,j,vis,grid);
                }
            }
        }
        return ans;
    }
};