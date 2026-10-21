class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue
        <pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>> pq;
        // yaha apan store karenge - differece / i /j  
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        pq.push({0,{0,0}});
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;
            for(int i =0 ;i<4;i++){
                int r = row + dr[i];
                int c = col + dc[i];
                if(r>=0 && c>=0 && r<n && c<m ){
                    int neff = max(abs(heights[r][c]-heights[row][col]),diff);
                    if(neff<dist[r][c]){
                        dist[r][c] = neff;
                        pq.push({neff,{r,c}});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};