
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2,
                               int k1, int k2) {
        long long k = (long long)k1 + k2;
        const int M = 100000;

        vector<long long> freq(M + 1, 0);
        long long sum = 0;

        for (int i = 0; i < nums1.size(); i++) {
            int d = abs(nums1[i] - nums2[i]);
            freq[d]++;
            sum += d;
        }

        if (sum <= k) return 0;

        for (int d = M; d > 0 && k > 0; d--) {
            if (freq[d] == 0) continue;

            long long cnt = min(freq[d], k);
            freq[d] -= cnt;
            freq[d - 1] += cnt;
            k -= cnt;
        }

        long long ans = 0;

        for (int d = 1; d <= M; d++) {
            ans += freq[d] * d * d;
        }

        return ans;
    }
};
