class Solution {
public:
    bool checkDivisibility(int n) {
        int k =n;
        int sum =0;
        int p=1;
        while(n){
            int x =n%10;
            sum+=x;
            p*=x;
          n/=10;}
         int z = sum + p;
        return k%z==0? true: false;
    }
};