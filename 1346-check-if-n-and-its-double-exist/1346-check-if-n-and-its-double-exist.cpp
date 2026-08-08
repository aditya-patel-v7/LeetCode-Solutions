class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n=arr.size();
        unordered_set<int> m;
      for(int i=0;i<n;i++){
         if(m.count(arr[i]*2)!=0){
            return true;
         }
         if (arr[i] % 2 == 0 && m.count(arr[i] / 2))
                return true;

         m.insert(arr[i]);
      }  
   return false; }
};