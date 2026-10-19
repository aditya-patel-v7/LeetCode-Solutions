class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(char c : s) mp[c]++;

        vector<pair<char,int>> vec(mp.begin(),mp.end());
        sort(vec.begin(),vec.end(),[](pair<char,int> &a , pair<char,int> &b){
            return a.second > b.second;
        });
        string res = "";
        for(auto it:vec){
            res.append(it.second,it.first);
        }
        return res;
    }
};