class Solution {
public:
    void dfs(vector<vector<char>>& grid, int r, int c){
        cout << r << " " << c << endl;
        int n = grid.size(), m = grid[0].size();
        vector<int>d = {-1,0,1,0,-1};
        grid[r][c] = 'x';
        for(int i = 0; i < 4; i++){
            int x = r + d[i], y = c + d[i+1];
            if(x >= 0 and x < n and y >= 0 and y < m and grid[x][y] == '1'){
                dfs(grid, x, y);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int islands = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j);
                    islands++;
                }
            }
        }
        return islands;
    }
};
