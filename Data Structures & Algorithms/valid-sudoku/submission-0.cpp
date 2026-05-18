class Solution {
public:
    bool isValidRow(int r, vector<vector<char>>& board){
        unordered_map<int,int>mp;
        for(int j = 0; j < 9; j++){
            if(mp.find(board[r][j]) != mp.end() and board[r][j] != '.')
                return false;
            mp[board[r][j]] = 1;
        }
        return true;
    }
    bool isValidCol(int c, vector<vector<char>>& board){
        unordered_map<int,int>mp;
        for(int i = 0; i < 9; i++){
            if(mp.find(board[i][c]) != mp.end() and board[i][c] != '.')
                return false;
            mp[board[i][c]] = 1;
        }
        return true;
    }
    bool isValidBox(int r, int c, vector<vector<char>>& board){
        unordered_map<int,int>mp;
        for(int i = r; i < r + 3 && i < 9; i++){
            for(int j = c; j < c + 3 && j < 9; j++){
                if(mp.find(board[i][j]) != mp.end() and board[i][j] != '.')
                    return false;
                mp[board[i][j]] = 1;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            if(!isValidRow(i, board) or !isValidCol(i, board))
                return false;
        }
        for(int i = 0; i < 9; i += 3){
            for(int j = 0; j < 9; j += 3){
                if(!isValidBox(i,j,board))
                    return false;
            }
        }
        return true;
    }
};
