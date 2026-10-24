class Solution {
public:

   int dfs(int i,int j,vector<vector<int>> &vis,vector<vector<int>> &grid , int &ans ){
    int n = grid.size();
    int m = grid[0].size();
    vis[i][j]=1;
    ans++;
    int dr[]={-1,1,0,0};
    int dc[]={0,0,-1,1};
    for(int d=0;d<4;d++){
        int r = i + dr[d];
        int c = j+dc[d];
        if(r>=0 && r<n && c<m && c>=0 && !vis[r][c] && grid[r][c]==1){
            dfs(r,c,vis,grid,ans);
        }
    }
    return ans ;
   }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
       int area=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    int ans =0;
                   area = max(area, dfs(i,j,vis,grid,ans));
                }
            }
        }
        return area;
    }
};