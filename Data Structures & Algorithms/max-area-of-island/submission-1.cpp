class Solution {
public:
    int max_area;
    int area;
    void dfs(vector<vector<int>>& grid, int r, int c){
        max_area = max(area, max_area);
        int n = grid.size(), m = grid[0].size();
        vector<int>d = {-1,0,1,0,-1};
        grid[r][c] = -1;
        for(int i = 0; i < 4; i++){
            int x = r + d[i], y = c + d[i+1];
            if(x >= 0 and x < n and y >= 0 and y < m and grid[x][y] == 1){
                area++;
                dfs(grid, x, y);
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        max_area = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    area = 1;
                    dfs(grid, i, j);
                }
            }
        }
        return max_area;
    }
};
