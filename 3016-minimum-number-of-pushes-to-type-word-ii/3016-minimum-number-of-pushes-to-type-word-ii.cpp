class Solution {
public:
    int minimumPushes(string word) {
        vector<int>v(26,0);
        int ans=0;
        for(char c:word){
            v[c-'a']++;
        }
        sort(v.begin(),v.end(),greater<int>());
        for(int i=0;i<26;i++){
         ans+=v[i]*(i / 8 + 1);
        }
  return ans;  }
};