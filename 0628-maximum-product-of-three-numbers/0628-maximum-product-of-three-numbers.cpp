class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        int a=0,b=0,c=0;
        int p1=INT_MIN;
        int p2=INT_MIN;
        sort(nums.begin(),nums.end());
      for(int i=0;i<2;i++){
        if(i==0){
        a=nums[n-1];
        b=nums[n-2];
        c=nums[n-3];
       p1= (a*b*c);
       p2=max(p1,p2); 
        }else{
         a=nums[0];
        b=nums[i];
        c=nums[n-1];
       p1= (a*b*c);
       p2=max(p1,p2);
        
      }
    
      }   
  return p2;  }
};