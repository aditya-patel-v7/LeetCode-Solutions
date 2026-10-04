class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
     int oldColor = image[sr][sc];
        if (oldColor == color) return image;

        int n = image.size();
        int m = image[0].size();
        
        queue<pair<int,int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;

        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nc >= 0 && nr < n && nc < m && image[nr][nc] == oldColor) {
                    image[nr][nc] = color;
                    q.push({nr, nc});
                }
            }
        }
        return image;   
    }
};


// class Solution {
// public:
//     void dfs(vector<vector<int>>& image, int r, int c, int oldColor, int newColor) {
//         int n = image.size();
//         int m = image[0].size();

//         if (r < 0 || r >= n || c < 0 || c >= m)
//             return;

//         if (image[r][c] != oldColor)
//             return;

//         image[r][c] = newColor;

//         dfs(image, r + 1, c, oldColor, newColor);
//         dfs(image, r - 1, c, oldColor, newColor);
//         dfs(image, r, c + 1, oldColor, newColor);
//         dfs(image, r, c - 1, oldColor, newColor);
//     }

//     vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
//         int oldColor = image[sr][sc];

      
//         if (oldColor == color)
//             return image;

//         dfs(image, sr, sc, oldColor, color);

//         return image;
//     }
// };