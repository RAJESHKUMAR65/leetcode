class Solution {
public:
// agai 2d matrix mein travel krna hein toh yaad rakhe [i+j] and [i-j]
// [i+j] agar uper sey neeche travel krne hein diagonally
//[i-j] agar neeche sey uper krna hein
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        // jaab musey diagonally traverse krna hein toh mein i+j,i-j
        // techanique use krunga
     unordered_map<int,vector<int>>mp;
     // sare element map mein dal diye
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            mp[i-j].push_back(mat[i][j]);
        }
     }
     // aagla kaam hein map kein vector ko sort krna
     for(auto &it:mp){
        sort(it.second.begin(),it.second.end());
     }

     // aab dal denge wapas matrix mein 
     // ulte sey dalenge taki dalne kein baad pop kr sekhe
     for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            mat[i][j]=mp[i-j].back();
            mp[i-j].pop_back();
        }
     }
        return mat;
    }
};