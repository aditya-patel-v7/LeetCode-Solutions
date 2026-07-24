class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXX = 2048; // 2048 kyu ki  nums[i] <= 1500 next greater power of 2  2^11

        vector<bool> pairXor(MAXX, false);
        vector<bool> tripletXor(MAXX, false);

        int n = nums.size();

        // All possible XORs of two elements (j <= k)
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                pairXor[nums[i] ^ nums[j]] = true;
            }
        }

        // XOR every pair XOR with every element
        for (int num : nums) {
            for (int x = 0; x < MAXX; x++) {
                if (pairXor[x]) {
                    tripletXor[num ^ x] = true;
                }
            }
        }

        int ans = 0;
        for (bool x : tripletXor)
            ans += x;

        return ans;
    }
};