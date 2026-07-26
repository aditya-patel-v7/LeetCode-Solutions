// class Solution {
// public:
// bool ispalindrom(string x){
//     int l =x.size();
//     int i=0,j=l-1;
//     while(i<=j){
//        if(x[i++]!=x[j--]){
//         return false;
//        }
//     }
//     return true;
// }
//     string longestPalindrome(string s) {
//        int n = s.size();
//        string a = "";
//        for(int i=0;i<n;i++){
//        string b="";
//         for(int j=i;j<n;j++){
//           b+=s[j];
//           if(ispalindrom(b) && b.size()>a.size()){
//             a=b;
//           }
//         }
//        } 
//    return a; }
// };

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0, maxLen = 1;

        auto expand = [&](int l, int r) {
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 > maxLen) {
                    maxLen = r - l + 1;
                    start = l;
                }
                l--;
                r++;
            }
        };

        for (int i = 0; i < n; i++) {
            expand(i, i);       // odd length
            expand(i, i + 1);   // even length
        }

        return s.substr(start, maxLen);
    }
};