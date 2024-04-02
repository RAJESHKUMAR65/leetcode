class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int pickP=0;
        int pickM=0;
        int pickG=0;
        
        int travelP=0;
        int travelM=0;
        int travelG=0;

        int last_indexP=-1;
        int last_indexM=-1;
        int last_indexG=-1;
          for(int i=0;i<garbage.size();i++)
          {
            string str=garbage[i];
            for(int j=0;j<str.length();j++)
            {
                if(str[j]=='P')
                {
                    pickP++;
                    last_indexP=i;
                }
                else if(str[j]=='M')
                {
                    pickM++;
                    last_indexM=i;

                }
                else if(str[j]=='G')
                {
                    pickG++;
                    last_indexG=i;
                }
            }
           
            
          }
            
          for(int i=0;i<travel.size();i++)
          {
            if(last_indexP>i )
            {
                travelP+=travel[i];

            }
            if(last_indexM>i )
            {
                travelM+=travel[i];

            }
            if(last_indexG>i)
            {
                travelG+=travel[i];

            }
          }
        //   cout<<travelP<<endl;
        //   cout<<travelM<<endl;
        //   cout<<travelG<<endl;
          return (pickP+travelP+pickM+travelM +pickG+travelG);
        
    }
};