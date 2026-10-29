class Solution {
public:
    bool dfs(int i,int j,string &ans,int n,int m , string word,vector<vector<char>>&board,vector<vector<int>> &vis){
        vis[i][j]=1;
        ans.push_back(board[i][j]);
           if(ans.size()>word.size()){
              ans.pop_back();
              vis[i][j]=0;
              return false;
           } 
        if(ans == word) return true;
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};
        for(int d =0;d<4;d++){
            int r =i+dr[d];
            int c = j + dc[d];
            if(r<n && r>=0 && c<m && c>=0 && !vis[r][c] && ans.size()<word.size()){
               if( dfs(r,c,ans,n,m,word,board,vis)) return true;;
            }
        }
        ans.pop_back();
        vis[i][j]=0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        char start = word[0];
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==start && !vis[i][j]){
                    string ans;
                   if( dfs(i,j,ans,n,m,word,board,vis)) return true;;
                     
                }
            }
        }
   return false;  }
};