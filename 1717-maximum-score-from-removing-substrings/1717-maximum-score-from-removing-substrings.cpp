class Solution {
public:
    string removePair(string s, char a, char b, int points, int &score) {
        stack<char> st;

        for (char c : s) {
            if (!st.empty() && st.top() == a && c == b) {
                st.pop();
                score += points;
            } else {
                st.push(c);
            }
        }

        string rem;
        while (!st.empty()) {
            rem += st.top();
            st.pop();
        }

        reverse(rem.begin(), rem.end());
        return rem;
    }

    int maximumGain(string s, int x, int y) {
        int score = 0;

        if (x >= y) {
            s = removePair(s, 'a', 'b', x, score);
            s = removePair(s, 'b', 'a', y, score);
        } else {
            s = removePair(s, 'b', 'a', y, score);
            s = removePair(s, 'a', 'b', x, score);
        }

        return score;
    }
};



