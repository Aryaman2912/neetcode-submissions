class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size();
        vector<vector<int>>poss, poss2, poss3;
        for(int i = 0; i < n; i++){
            if((triplets[i][0] <= target[0]) && (triplets[i][1] <= target[1]) && (triplets[i][2] <= target[2]))
                poss.push_back(triplets[i]);
        }
        if(!poss.size())
            return false;
        vector<int>x = poss[0];
        for(int i = 0; i < poss.size(); i++){
            x[0] = max(x[0], poss[i][0]);
            x[1] = max(x[1], poss[i][1]);
            x[2] = max(x[2], poss[i][2]);
        }
        if((x[0] == target[0]) && (x[1] == target[1]) && (x[2] == target[2]))
            return true;
        return false;
    }
};