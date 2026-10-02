class Solution {
public:
    vector<string> ans;
    void dfs(string s , int o , int c , int n){
        if(s.length()==2*n){
            ans.push_back(s);
        }
        if(o<n){
            dfs(s+'(',o+1,c,n);
        }
        if(c<o){
            dfs(s+')',o,c+1,n);
        }
    }
    vector<string> generateParenthesis(int n) {
     dfs("",0,0,n);
     return ans;
    }
};