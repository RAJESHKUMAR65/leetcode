class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int miniTimediff=INT_MAX;
        sort(timePoints.begin(),timePoints.end());
        for(int i=0;i<=timePoints.size()-2;i++){
            string str1=timePoints[i];
            string str2=timePoints[i+1];
            int hours1=stoi(str1.substr(0,2));
            int minute1=stoi(str1.substr(3,2));
            int timeMin1=hours1*60+minute1;
            int hours2=stoi(str2.substr(0,2));
            int minute2=stoi(str2.substr(3,2));
            int timeMin2=hours2*60+minute2;

            int diff=abs(timeMin1-timeMin2);
            
            miniTimediff=min(diff,miniTimediff);
            }

            string str1=timePoints[0];
            string str2=timePoints[timePoints.size()-1];
            int hours1=stoi(str1.substr(0,2));
            int minute1=stoi(str1.substr(3,2));
            int timeMin1=(hours1*60+minute1)+1440;
            int hours2=stoi(str2.substr(0,2));
            int minute2=stoi(str2.substr(3,2));
            int timeMin2=hours2*60+minute2;

            int diff=abs(timeMin1-timeMin2);
            
            miniTimediff=min(diff,miniTimediff);


       return miniTimediff;
    }
};