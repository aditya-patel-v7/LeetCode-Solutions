class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
       vector<pair<string,int>> vec;
       unordered_map<string,int> mp;
       for(auto &i : words){
        mp[i]++;
       }
       for(auto it : mp){
        vec.push_back({it.first,it.second});
       }
       sort(vec.begin(),vec.end(),[](pair<string,int> &a , pair<string,int> &b){
        if(a.second == b.second){
            return a.first<b.first;
        }
        return a.second>b.second;
       });
       vector<string>ans;
       int i =0;
       while(i<k){
        ans.push_back(vec[i++].first);
       }
        return ans;
       }
};