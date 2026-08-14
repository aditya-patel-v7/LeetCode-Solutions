class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
     unordered_map<string,int> m;
     vector<string>ans;
    int n=s.size();
   
    for(int i=0;i+10<=n;i++){
        string x= s.substr(i,10);
        m[x]++;
        if(m[x]==2){
          ans.push_back(x);
        }
    }
  
   return ans; }
};