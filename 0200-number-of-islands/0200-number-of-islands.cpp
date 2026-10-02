class Solution {
public:
       void bfs(int m, int n ,int i , int j , vector<vector<int>> &vis , vector<vector<char>> & grid){
            vis[i][j]=1;
           queue<pair<int,int>> q;
            q.push({i,j});
            while(!q.empty()){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                // for(int l=-1;l<=1;l++){
                //     for(int k=-1;k<=1;k++){
                //         int x=0;
                //         int y =0 ;
                //         x=r+l;
                //         y=c+k;
                //         if(x >= 0 && x < n && y >= 0 && y < m &&
                //            !vis[x][y] && grid[x][y] == '1'){
                //             vis[x][y]=1;
                //             q.push({x,y});
                //         }
                //     }
                // }


                  int dr[] = {-1, 1, 0, 0};
                int dc[] = {0, 0, -1, 1};

                 for(int d = 0; d < 4; d++) {

                    int x = r + dr[d];
                   int y = c + dc[d];

               if(x >= 0 && x < n && y >= 0 && y < m &&
                  !vis[x][y] && grid[x][y] == '1') {

                 vis[x][y] = 1;
                   q.push({x, y});
                     }
}
            }
        }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int c =0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                     bfs(m,n,i,j,vis,grid);
                     c++;
                }
            }
        }
    return c; }
};