class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;
        int fresh = 0;

        // Step 1: Initialize queue with rotten oranges & count fresh
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        // If no fresh oranges
        if (fresh == 0) return 0;

        int minutes = 0;
        vector<pair<int,int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};

        // Step 2: BFS
        while (!q.empty()) {
            int size = q.size();
            bool spread = false;

            for (int i = 0; i < size; i++) {
                auto [x, y] = q.front();
                q.pop();

                for (auto &d : directions) {
                    int nx = x + d.first;
                    int ny = y + d.second;

                    // Check bounds and fresh orange
                    if (nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2; // rot it
                        q.push({nx, ny});
                        fresh--;
                        spread = true;
                    }
                }
            }

            if (spread) minutes++;
        }

        // If fresh oranges remain
        return (fresh == 0) ? minutes : -1;
    }
};