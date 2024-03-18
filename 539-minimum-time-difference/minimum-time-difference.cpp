class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int Time[timePoints.size()];
    for (int i=0;i<timePoints.size();i++)
    {
        string s=timePoints[i];
        s.erase(2,1);
       
        int con=stoi(s);
        int hour= con/100;
        int minute=con%100;
        int ans =(hour*60)+minute;
        Time[i]=ans;;
    }
     
     sort(Time,Time+timePoints.size());
     int mini=INT_MAX;
     for(int i=0;i<timePoints.size();i++)
     {
        if(i+1<timePoints.size())
       {
         int a=Time[i+1]-Time[i];
         if(a<mini)
         {
            mini=a;
         }
        
        

       }
        
     }

      
    
    int n=timePoints.size()-1;
    int last=(Time[0]+1440)-Time[n];
    cout<<last;
    
    if(last<mini)
    {
        return last;
    }
    else
    {
        return mini;
    }
    }
};