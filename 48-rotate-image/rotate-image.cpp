class Solution {
public:
    void reverse(vector<int> &matrix)
    {
        int s=0;
        int e=matrix.size()-1;
        while(s<=e)
        {
            swap(matrix[s],matrix[e]);
            s++;
            e--;
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        // phele tranpose kiya matrix ko
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=i;j<matrix[i].size();j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        // pr hr row ko reverse kiya 
    for(int i=0;i<matrix.size();i++)
    {
        reverse(matrix[i]);
    }
    }
};