class Solution {
public:
// kyuki maine koi base nhi lekha hei

  bool issafe(vector<vector<char>>& board,char val ,int curr_row,int curr_col)
  {
    for(int i=0;i<board.size();i++)
    {
    // row check krunga
      if(board[curr_row][i]==val)
      {
        return false;
      }
      // col check krunga

      if(board[i][curr_col]==val)
      {
        return false;
      }

      // 3*3 matrix check krunga
      if(board[3*(curr_row/3)+(i/3)][3*(curr_col/3)+(i%3)]==val)
      {
        return false;
      }
    }
// yaha tak pauche go matlab tino condition check kr le 
    return true;
  }
   bool solve(vector<vector<char>>& board)
   {
    int n=board[0].size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            // empty place hei
            if(board[i][j]=='.')
            {
                for(int val='1';val<='9';val++)
                {
                  if(issafe(board,val,i,j))
                  {
                    board[i][j]=val;
                    bool aagekaanswer=solve(board);
                    if(aagekaanswer==true)
                    {
                        return true;
                    }
                    else{
                        // backtrack kr do
                        board[i][j]='.';
                    }
                 
                   }
                }
                return false;
            }
            
        }
    }
    //tum sare case dekh leho 
    return true;
   }
    void solveSudoku(vector<vector<char>>& board) {

       solve(board);

    }
};