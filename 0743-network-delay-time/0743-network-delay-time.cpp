class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
      vector<pair<int,int>>adj[n+1];
      for(auto it:times){
        adj[it[0]].push_back({it[2],it[1]});
      } 
      vector<int> dist(n+1,1e9);
      priority_queue<pair<int,int>,
      vector<pair<int,int>>,
      greater<pair<int,int>>>q;
      q.push({0,k});
      dist[k]=0;
      while(!q.empty()){
        int wt = q.top().first;
        int node = q.top().second;
        q.pop();
        for(auto it:adj[node]){
            int ew = it.first;
            int nd = it.second;
            if(wt + ew <dist[nd]){
                dist[nd] = wt + ew;
                q.push({dist[nd],nd});
            }
        }
      }
      int ans = *max_element(dist.begin()+1,dist.end());

     if(ans == 1e9)
    return -1;

     return ans;
    }
};