class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i :nums){
            mp[i]++;
        }
        int ans = -1;
        for(int i:nums){
          if(mp[i]>1) continue;;
          ans = i;
        }
   return ans ; }
};