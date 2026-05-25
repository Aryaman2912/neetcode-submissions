class Solution {
public:
    vector<vector<int>>dp;
    int max_path;
    int dfs(vector<vector<int>>& matrix, int r, int c){
        // cout << r << " " << c << endl;
        if(dp[r][c] != -1)
            return dp[r][c];
        dp[r][c] = 1;
        int n = matrix.size(), m = matrix[0].size();
        vector<int>dir = {-1,0,1,0,-1};
        int path = 1;
        for(int i = 0; i < 4; i++){
            int x = r + dir[i];
            int y = c + dir[i+1];
            if(x >= 0 and x < n and y >= 0 and y < m and matrix[x][y] > matrix[r][c]){
                path = max(path, 1 + dfs(matrix,x,y)); 
            } 
        }
        dp[r][c] = path;
        max_path = max(path, max_path);
        return path;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        for(int i = 0; i < n; i++){
            dp.push_back(vector<int>(m,-1));
        }
        max_path = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(dp[i][j] == -1){
                    dfs(matrix,i,j);
                }
            }
        }
        return max_path;
    }
};
