class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const int MOD = 1000000007;
        int n = s.size();

        vector<long long> pow10(n + 1, 1);
        for (int i = 1; i <= n; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        vector<int> digitSum(n + 1, 0);
        vector<int> nonZeroCount(n + 1, 0);
        vector<long long> prefixNum(n + 1, 0);

        for (int i = 0; i < n; i++) {
            int digit = s[i] - '0';
            digitSum[i + 1] = digitSum[i] + digit;
            nonZeroCount[i + 1] = nonZeroCount[i] + (digit != 0);

            if (digit != 0)
                prefixNum[i + 1] = (prefixNum[i] * 10 + digit) % MOD;
            else
                prefixNum[i + 1] = prefixNum[i];
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            int sum = digitSum[r + 1] - digitSum[l];
            int cnt = nonZeroCount[r + 1] - nonZeroCount[l];

            long long num = (prefixNum[r + 1] - prefixNum[l] * pow10[cnt] % MOD + MOD) % MOD;

            ans.push_back((num * sum) % MOD);
        }

        return ans;
    }
};