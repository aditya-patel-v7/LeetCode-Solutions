class Solution {
public:
    int singleNumber(vector<int>& nums) {
//         int ans=0;
//         unordered_map<int,int> mp;
//         for(int i : nums){
//             mp[i]++;
//         }
//         for(auto i:mp){
//             if(i.second == 1){
//                 ans = i.first;
//             }
//         }
//    return ans ;
 int ans =0;
 for(int i : nums){
  ans ^= i;
 }
  return ans; }
};