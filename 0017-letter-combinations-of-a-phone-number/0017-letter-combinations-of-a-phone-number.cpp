class Solution {
public:
    vector<string> ans;
    vector<string>mp={
        "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
    };

    void dfs(string &digits,string &curr,int idx){
       if(idx == digits.size()){
        ans.push_back(curr);
        return;
       }
      string let = mp[digits[idx] - '0'];
      for(char ch : let){
        curr.push_back(ch);
        dfs(digits,curr,idx+1);
        curr.pop_back();
      }
    }
    vector<string> letterCombinations(string digits) {
       if(digits.empty()) return {};
       string curr = "";
       dfs(digits,curr,0);
       return ans;
        
    }
};