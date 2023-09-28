class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int t=0,gt=-1,pt=-1,mt=-1,i,j,tr1=0,tr2=0,tr3=0;

        for(i=0;i<garbage.size();i++){
            t+=garbage[i].size();
            if(garbage[i].find("G")!= string::npos)gt=i;
            if(garbage[i].find("M")!= string::npos)mt=i;
            if(garbage[i].find("P")!= string::npos)pt=i;
        }

        for(i=0;i<gt;i++)tr1+=travel[i];
        for(i=0;i<mt;i++)tr2+=travel[i];
        for(i=0;i<pt;i++)tr3+=travel[i];
        
        return (t+tr1+tr2+tr3);

    }
};