class Solution {
public:
    int findMinDifference(vector<string>& timepoints) {
        vector<int>time;
        int minute,i,j,ans=INT_MAX;
        string temp;
        for(i=0;i<timepoints.size();i++){
            minute=0;temp="";
            for(j=0;j<2;j++){
                temp+=timepoints[i][j];
            }
            minute=60* stoi(temp);
            temp="";
            for(j=3;j<5;j++){
                temp+=timepoints[i][j];
            }
            minute+=stoi(temp);
            time.push_back(minute);
        }
        sort(time.begin(),time.end());
        for(i=0;i<time.size()-1;i++){
            ans=min(ans,time[i+1]-time[i]);
        }
        ans=min(ans,time[0]+1440 - time[time.size()-1]);
        return ans;
    }
};