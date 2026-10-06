class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
         int n = s.size();
         for(int i =0;i<n;i++){
            if(!st.empty() && st.top()=='(' && s[i]==')' ){
               st.pop();
               continue;
            }
            st.push(s[i]);
         }
         int ans =0;
        while(!st.empty()){
            st.pop();
            ans++;
        }
   return ans ; }
};