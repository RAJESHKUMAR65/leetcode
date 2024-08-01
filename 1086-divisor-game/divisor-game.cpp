class Solution {
public:
   void solveUsingRecursion(int n,bool &alice){
    if(n==0){
        return;
    }
    for(int i=1;i<n;i++)
    {
        if(n%i==0){
            alice=!alice;
            solveUsingRecursion(n-i,alice);
            break;
        }
    }

    

   }
    bool divisorGame(int n) {
        bool alice=false;
        solveUsingRecursion(n,alice);
        return alice;
        
    }
};