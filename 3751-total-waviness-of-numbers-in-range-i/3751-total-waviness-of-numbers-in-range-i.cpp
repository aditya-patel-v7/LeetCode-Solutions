class Solution {
public:
    int totalWaviness(int num1, int num2) {
        long long count=0;
        if (num1<100){
         num1 = max(num1, 100); 
        }
        for(int i=num1;i<=num2;i++){
             string j=to_string(i);
             int a=0;
             int b=1;
             int c=2;
                while(c < j.length()){
                   if ((j[a]<j[b] && j[b]>j[c]) || (j[a]>j[b] && j[b]<j[c])){
                    count++;
              
                }
                  a++;
                    b++;
                    c++;
                   }
               
             
                }
            return count;
    }
};