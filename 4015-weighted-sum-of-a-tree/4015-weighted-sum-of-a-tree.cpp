class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
      int n =parent.size();
      vector<vector<int>>v(n);

      for(int i=1;i<n;i++){
         v[parent[i]].push_back(i);
      }  
      vector<int> depth(n);
      queue<int> q;
      q.push(0);
      depth[0]=1;
      int height = 1;
      while(!q.empty()){
        int node = q.front();
        q.pop();
        height= max(height,depth[node]);
        for(int x: v[node]){
            depth[x]=depth[node]+1;
            q.push(x);

        }
      }
      long long ans =0;
      for(int i=0;i<n;i++){
        ans+=1LL*nums[i]*(height-depth[i]+1);
      }
   return ans; }
};