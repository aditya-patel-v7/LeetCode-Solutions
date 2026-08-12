class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map<int,int>m;
    int i=0,j=0;
    int count=0;
    while(j<n){
        m[nums[j]]++;
        while(m[nums[j]]>k){
            m[nums[i]]--;
            i++;
        }
        count= max(count,j-i+1);
        j++;
    }
      return count;  }
};