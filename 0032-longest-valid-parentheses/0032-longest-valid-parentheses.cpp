// class Solution {
// public:
//     int longestValidParentheses(string s) {
//         int ans = 0;

//         for (int i = 0; i < s.size(); i++) {
//             int balance = 0;

//          for (int j = i; j < s.size(); j++) {

//          if (s[j] == '(')
//                     balance++;
//          else
//            balance--;

//          if (balance < 0)
//            break;

//           if (balance == 0)
//                     ans = max(ans, j - i + 1);
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);

        int ans = 0;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(') {
                st.push(i);
            }
            else {
                st.pop();

                if (st.empty()) {
                    st.push(i);
                }
                else {
                    int len = i - st.top();
                    ans = max(ans, len);
                }
            }
        }

        return ans;
    }
};