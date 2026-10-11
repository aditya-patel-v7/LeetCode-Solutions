class Solution {
public:
    
    bool dfs(int i , vector<int> &vis, vector<int> &pathvis, vector<int> &ans , vector<vector<int>> &graph){
        vis[i]=1;
        pathvis[i]=1;
        for(int it : graph[i] ){
           if(!vis[it]){
            if(dfs(it,vis,pathvis,ans,graph)) {
           
                return true;
            }
           }
           else if(pathvis[it]==1){
           
            return true;
           }
        }
        pathvis[i]=0;
        ans.push_back(i);
        return false;
    }
 
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,0);
        vector<int> pathvis(n,0);
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(!vis[i]){
               dfs(i,vis,pathvis,ans,graph);
            }
        }
        sort(ans.begin(), ans.end());
   return ans; }
};