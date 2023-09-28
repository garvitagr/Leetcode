class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int>beams(1);
        int ct=0,i,j,ans=0;
        for(i=0;i<bank.size();i++){
            ct=0;
            for(j=0;j<bank[i].size();j++){
                if(bank[i][j]=='1')ct++;
            }
            if(ct>0)beams.push_back(ct);
        }
        for(i=1;i<beams.size()-1;i++){
            ans+=(beams[i]*beams[i+1]);
        }
        return ans;
    }
};