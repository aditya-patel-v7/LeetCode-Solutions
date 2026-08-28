class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        int i = 0, j = 0;
        int one = 0;
        string ans = "";

        while (j < n) {
            if (s[j] == '1')
                one++;

            while (one > k) {
                if (s[i] == '1')
                    one--;
                i++;
            }

            if (one == k) {
                while (s[i] == '0')
                    i++;

                string x = s.substr(i, j - i + 1);

                if (ans == "" ||
                    x.length() < ans.length() ||
                    (x.length() == ans.length() && x < ans)) {
                    ans = x;
                }
            }

            j++;
        }

        return ans;
    }
};