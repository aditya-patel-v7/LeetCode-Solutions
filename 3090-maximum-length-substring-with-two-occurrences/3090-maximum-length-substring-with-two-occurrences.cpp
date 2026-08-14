class Solution {
public:
    int maximumLengthSubstring(string s) {
       int n = s.length() ;
       int i=0,j=0;
       int count=0;
       unordered_map<char,int> m;
       while(j<n){
        m[s[j]]++;
        while(m[s[j]]>2){
            m[s[i]]--;
            i++;
        }
        count = max(count,j-i+1);
        j++;
       }
   return count; }
};