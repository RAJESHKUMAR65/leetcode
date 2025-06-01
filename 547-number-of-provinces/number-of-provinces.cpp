class Solution {
public:
void dfs(int src,unordered_map<int,vector<int>>&adjlist,unordered_map<int,bool>&visited){
    visited[src]=true;
    for(auto nbr:adjlist[src]){
        if(!visited[nbr]){
            
            dfs(nbr,adjlist,visited);
        }
        
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int,vector<int>>adjlist;
        for(int i=0;i<isConnected.size();i++){
          for(int j=0;j<isConnected[i].size();j++){
            if(isConnected[i][j]==1){
              int u=i+1;
              int v=j+1;
            adjlist[u].push_back(v);}}}

        for(auto i:adjlist){
            cout<<i.first<<":";
              for(auto nbr:i.second){
                cout<<nbr<<" ,";
              }
              cout<<endl;
        }

       unordered_map<int ,bool>visited;
       int count=0;
       for(int i=1;i<=isConnected.size();i++){
          if(!visited[i]){
             count++;
            dfs(i,adjlist,visited);
            
          }
       }
       return count;
    }
};