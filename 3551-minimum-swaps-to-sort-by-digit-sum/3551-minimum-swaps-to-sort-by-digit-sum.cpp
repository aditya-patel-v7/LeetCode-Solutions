class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> v;

        for (int x : nums) {
            int sum = 0, y = x;

            while (y > 0) {
                sum += y % 10;
                y /= 10;
            }

            v.push_back({sum, x});
        }

        sort(v.begin(), v.end());

        unordered_map<int, int> pos;
        for (int i = 0; i < n; i++) {
            pos[nums[i]] = i;
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == v[i].second) continue;

            int j = pos[v[i].second];

            pos[nums[i]] = j;
            pos[nums[j]] = i;

            swap(nums[i], nums[j]);
            ans++;
        }

        return ans;
    }
};