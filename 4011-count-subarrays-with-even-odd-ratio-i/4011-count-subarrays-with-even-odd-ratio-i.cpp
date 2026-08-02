class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size();
        int od=0;
        int ev=0;
        int count=0;
        for(int i=0;i<n;i++){
            od=0;
            ev=0;
            for(int j=i;j<n;j++){
               if(nums[j]%2==0) ev++;
                else od++;
                if ((1LL*ev*b)<=(1LL*od*a)){
                    count++;
                }

            }
        }
   return count;  }
};