class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int> l(n,0);
        vector<int> r(n,0);
        vector<int> ans;
         int s=0,j=0;
         for(int i=1 ;i<n;i++){
          s+=nums[j];
          l[i]=s;
          j++;
         }
         s=0,j=n-1;
     for(int i=n-2 ;i>=0;i--){
          s+=nums[j];
          r[i]=s;
          j--;
         }
     for(int i=0;i<n;i++){
        ans.push_back(abs(l[i]-r[i]));
     }
        
   return ans; }
};