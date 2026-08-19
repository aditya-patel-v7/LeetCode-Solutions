class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> mp;

        for (auto &seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            mp[row] |= (1 << (col - 1));
        }

        int ans = (n - mp.size()) * 2;

        int left = 0b0000011110;
        int middle = 0b0001111000;
        int right = 0b0111100000;

        for (auto &[row, mask] : mp) {
            if ((mask & left) == 0 && (mask & right) == 0) {
                ans += 2;
            }
            else if ((mask & left) == 0 ||
                     (mask & middle) == 0 ||
                     (mask & right) == 0) {
                ans += 1;
            }
        }

        return ans;
    }
};