class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        //unordered map
        //i-j conecpt use krunga jaab bhi matrix mein diagonlly traverse krna hoga
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                mp[i-j].push_back(mat[i][j]);
            }
        }
        // sort the map
        for(auto &i:mp){
            sort(i.second.begin(),i.second.end());
        }
     

        for(int i=mat.size()-1;i>=0;i--){
            for(int j=mat[i].size()-1;j>=0;j--){
                mat[i][j]=mp[i-j].back();
                mp[i-j].pop_back();
            }
        }
        return mat;
    }
};