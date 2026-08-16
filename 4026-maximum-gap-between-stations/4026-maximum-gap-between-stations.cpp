class Solution {
public:
    int maximumGap(string skill, string station) {
        int n = skill.length();
        int m= station.length();
        if(n==1) return 0;

        vector<int>l(n);
        vector<int>r(n);
        int ptr =0;
        for(int i=0;i<n;i++){
            while(ptr <m && station[ptr] != skill[i]){
                ptr++;
            }
            l[i]=ptr++;
        }
        ptr = m-1;
        for(int i= n-1;i >=0; --i){
            while(ptr >=0 && station[ptr]!= skill[i]){
                ptr--;
            }
            r[i]=ptr--;
            
        }
     int g =0;
        for(int i=1;i<n;i++){
            g = max(g,r[i]-l[i-1]);
        }
  return g;  }
};