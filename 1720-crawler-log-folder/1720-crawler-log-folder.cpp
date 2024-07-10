class Solution {
public:
    int minOperations(vector<string>& logs) {
        int i,ans=0;
        for(i=0;i<logs.size();i++){
            if(logs[i][0]!='.')ans++;
            else if(logs[i][0]=='.' and logs[i][1]=='.')ans--;
            ans=(ans<0)?0:ans;
        }
        return ans;
    }
};