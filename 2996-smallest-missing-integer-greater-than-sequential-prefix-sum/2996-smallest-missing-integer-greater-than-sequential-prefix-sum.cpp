class Solution {
public:
    int missingInteger(vector<int>& nums) {
    unordered_map<int,int> m;
    int n = nums.size();
    for(int i:nums){
        m[i]++;
    }
    int sum = nums[0];
    for(int j=1;j<n;j++){
        if(nums[j] != nums[j-1]+1) break;
        sum+=nums[j];
    }
 
    while(m.find(sum)!=m.end()){
        sum++;
    }
   return sum; }
};