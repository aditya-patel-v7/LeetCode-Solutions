class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n=positions.size();
        vector<int> actual(n);
        for(int i=0;i<n;i++){
            actual[i]=i;
        }
        auto lambda=[&](int &i,int &j){
            return (positions[i]<positions[j]);
        };
        sort(begin(actual),end(actual),lambda);
        vector<int> r;
        stack<int>st;
        for(int &curr:actual){
            if(directions[curr]=='R'){
                st.push(curr);
            }else{
                while(!st.empty() && healths[curr]>0){
                    int tp=st.top();
                    st.pop();
                    if(healths[tp]>healths[curr]){
                        healths[tp]-=1;
                        healths[curr]=0;
                        st.push(tp);
                    }else if (
                        healths[tp]<healths[curr]){
                            healths[curr]-=1;
                            healths[tp]=0;
                        }else{
                            healths[curr]=0;
                            healths[tp]=0;
                        }
                    }
                }
            }
        
            for(int i=0;i<n;i++){
                if(healths[i]>0){
                    r.push_back(healths[i]);
                }
           }
           return r;
        
    }
};