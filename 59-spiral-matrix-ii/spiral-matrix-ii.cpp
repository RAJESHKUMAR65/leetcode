class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
            vector<vector<int>> matrix(n, vector<int>(n, 0));
        int dir=0;
        int top=0;
        int left=0;
        int down=n-1;
        int right=n-1;
        int number=1;
        while(top<=down && left<=right){
            if(number>n*n){
                break;
            }
             if(dir==0){
                for(int i=left;i<=right;i++){
                    matrix[top][i]=number;
                    number+=1;
                }
                top++;
             }
             if(dir==1){
                for(int i=top;i<=down;i++){
                    matrix[i][right]=number;
                    number+=1;
                }
                right--;
             }
             if(dir==2){
                for(int i=right;i>=left;i--){
                    matrix[down][i]=number;
                    number+=1;
                }
                down--;
             }
             if(dir==3){
                for(int i=down;i>=top;i--){
                    matrix[i][left]=number;
                    number+=1;
                }
                left++;
             }

             dir+=1;
             if(dir==4) dir=0;

        }
        return matrix;
    }
};