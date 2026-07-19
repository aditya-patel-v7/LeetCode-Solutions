class Solution {
public:
    int maxCoins(vector<int>& piles) {
      sort(piles.begin(), piles.end(),greater<int>());
        int n = piles.size();
        int ans = 0;
        int k=n/3;
        for(int i=1;i<n-k;i=i+2)
        {
            ans+=piles[i];
        }

   return ans ; }
};