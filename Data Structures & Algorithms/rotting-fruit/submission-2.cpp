class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        bool fs = false;
        queue<vector<int>>q;
        vector<int>dir = {-1,0,1,0,-1};
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1)
                    fs = true;
                if(grid[i][j] == 2)
                    q.push({i,j});
            }
        }
        int minutes = -1;
        if(!q.size() and !fs)
            return 0;
        while(!q.empty()){
            int t = q.size();
            for(int i = 0; i < t; i++){
                vector<int>v = q.front();
                q.pop();
                for(int j = 0; j < 4; j++){
                    int r = v[0] + dir[j];
                    int c = v[1] + dir[j+1];
                    if((r >= 0) and (r < n) and (c >= 0) and (c < m) and (grid[r][c] == 1)){
                        grid[r][c] = 2;
                        q.push({r,c});
                    }
                }
            }
            minutes++;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1)return -1;
            }
            cout << endl;
        }
        if(q.size()) return -1;
        return minutes;
    }
};