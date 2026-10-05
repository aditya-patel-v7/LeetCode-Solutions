class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> ans(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0 ; j<m ;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        while(!q.empty()){
           int x = q.front().first.first;
           int y = q.front().first.second;
           int dis = q.front().second;
           q.pop();
           ans[x][y]=dis;
           int dr[]={-1,1,0,0};
           int dc[]={0,0,-1,1};
           for(int d=0;d<4;d++){
            int r = x + dr[d];
            int c = y + dc[d];
            if(r<n && r>=0 && c>=0 && c<m && !vis[r][c]){
                vis[r][c]=1;
                q.push({{r,c},dis+1});
            }
           }

        }
   return ans ; }
};