class Solution {
public:
    string losingPlayer(int x, int y) {
       
       bool flag=false;
      while(x!=0 || y!=0){
          if(x>=1 && y>=4){
             x=x-1;
             y=y-4;
             flag=!flag;
          }
          else{
            break;
          }
      }
      if(flag){
        return "Alice";
      }
      else{
        return "Bob";
      }
    }
};