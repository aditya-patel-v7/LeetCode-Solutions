class Solution {
public:
     int first(vector<int> &nums,int target){
        int n = nums.size();
        int st = 0;
        int end = n-1;
        int ans = -1;
        while(st<=end){
            int mid = st+(end-st)/2;
            if(nums[mid]==target){
                ans = mid;
                end = mid-1;
            }
            else if(nums[mid]<target){
                st = mid+1;
            }else{
                end = mid-1;
            }
        }
        return ans;
     }
     int second(vector<int>& nums, int target){
        int n = nums.size();
        int ans =-1;
        int st =0;
        int end = n-1;
        while(st<=end){
          int mid = st+(end - st)/2;
           if(nums[mid]==target){
            ans = mid;
            st = mid+1;
           }else if(nums[mid]<target){
            st=mid+1;
           }else{
            end = mid-1;
           }
        }
        return ans;
     }
    vector<int> targetIndices(vector<int>& nums, int target) {
    vector<int>res;
    sort(nums.begin(),nums.end());
    int f = first(nums,target);
    int s = second(nums,target);
    if(f==-1) return res;
    for(int i = f;i<=s;i++){
        res.push_back(i);
    }
    return res;
    }
};