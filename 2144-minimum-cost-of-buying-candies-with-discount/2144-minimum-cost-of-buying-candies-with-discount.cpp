class Solution {
public:
    int minimumCost(vector<int>& cost) {
       if (cost.size()==2){
        return (cost[0]+cost[1]);
       } 
    sort(cost.begin(),cost.end(),greater<int>());
    int sum=0 ,count=0;
    for(int i:cost){
        if(count<2){
            sum+=i;
         count++;
        }
         else{
        count=0;
    }
   }
     return sum; }
};