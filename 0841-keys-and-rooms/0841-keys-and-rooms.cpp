class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        int m = rooms[0].size();
        vector<int>vis(n,0);
        queue<int>q;
        q.push(0);
        vis[0]=1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int i : rooms[node]){
            if(!vis[i]){
                    vis[i]=1;
            q.push(i);
            }
            }
        }
        for(int i=0;i<n;i++){
            if(vis[i]!=1) return false;
        }
       
       return true;     }
};