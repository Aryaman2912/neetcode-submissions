class Solution {
public:
    bool check(vector<vector<char>>& board, int r, int c, string word, int ind){
        if(board[r][c] != word[ind])
            return false;
        if(ind == word.size() - 1)
            return true;
        int n = board.size(), m = board[0].size();
        vector<int>dir = {-1,0,1,0,-1};
        char temp = board[r][c];
        board[r][c] = '.';
        for(int i = 0; i < 4; i++){
            int x = r + dir[i], y = c + dir[i+1];
            if(x >= 0 and x < n and y >= 0 and y < m and board[x][y] != '.' and check(board,x,y,word,ind+1))
                return true;
        }
        board[r][c] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(check(board,i,j,word,0))
                    return true;
            }
        }
        return false;
    }
};