class Solution {
    public:
        int orangesRotting(vector<vector<int>>& grid) {
            int rows = grid.size();
            int cols = grid[0].size();
    
            queue<pair<int, int>> q;
            int fresh = 0;
    
            // Step 1: Add all rotten oranges to queue and count fresh oranges
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if (grid[i][j] == 2) {
                        q.push({i, j});
                    } else if (grid[i][j] == 1) {
                        fresh++;
                    }
                }
            }
    
            if (fresh == 0) return 0;
    
            int minutes = 0;
            vector<pair<int, int>> directions = {
                {-1, 0}, // up
                {1, 0},  // down
                {0, -1}, // left
                {0, 1}   // right
            };
    
            while (!q.empty()) {
                int size = q.size();
                bool rottedThisMinute = false;
    
                for (int i = 0; i < size; i++) {
                    pair<int, int> current = q.front();
                    q.pop();
                    int x = current.first;
                    int y = current.second;
    
                    for (int d = 0; d < 4; d++) {
                        int dx = directions[d].first;
                        int dy = directions[d].second;
    
                        int nx = x + dx;
                        int ny = y + dy;
    
                        if (nx >= 0 && ny >= 0 && nx < rows && ny < cols && grid[nx][ny] == 1) {
                            grid[nx][ny] = 2;
                            q.push({nx, ny});
                            fresh--;
                            rottedThisMinute = true;
                        }
                    }
                }
    
                if (rottedThisMinute) {
                    minutes++;
                }
            }
    
            return (fresh == 0) ? minutes : -1;
        }
    };
    