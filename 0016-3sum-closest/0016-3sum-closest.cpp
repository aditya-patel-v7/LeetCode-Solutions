
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n= nums.size() ;
     sort (nums.begin(),nums.end());
     int close=0;
     int x=0,y=0; 
     int m=INT_MAX;
     for(int i=0;i<n-2;i++){
     x=i+1;
     y=n-1 ;
     while(x<y){
        int k=nums[x]+nums[y]+nums[i]-target;
        if(abs(k)<m){
            m=abs(k);
            close=nums[x]+nums[y]+nums[i];
        }
          if(k < 0){
    x++;
       }
        else if(k > 0){
    y--;
        }
      else{
      return close;
       }
     }
     }
   return close; }
};