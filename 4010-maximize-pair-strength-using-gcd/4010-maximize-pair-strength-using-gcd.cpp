class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        int n=nums.size();
        long long strength =0;
    
        for(int i=0;i<n;i++ ){
            for(int j=i+1;j<n;j++){
               long long g=gcd(nums[i],nums[j]);
                long long m = 1LL * nums[i] * nums[j];
               strength = max(strength,(m/(g*g)));

            }
        }
   return strength; }
};