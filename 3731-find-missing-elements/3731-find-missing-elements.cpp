class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>ans;
      int m=*max_element(nums.begin(),nums.end());
      int n=*min_element(nums.begin(),nums.end());
      unordered_set<int>s(nums.begin(),nums.end());
      for(int i=n+1;i<m;i++){
        if(!s.count(i)){
            ans.push_back(i);
        }
      }
   return ans; }
};