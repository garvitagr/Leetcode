class Solution {
public:
    vector<string> letterCombinations(string s) {
        map<int,vector<char>>mp;
        vector<string>ans;
        if(s.size()==0)return ans;
        if(s.size()==1){
            s+="000";
        }
       else if(s.size()==2){
            s+="00";
        }
        else if(s.size()==3){
            s+="0";
        }

        string temp;
        mp[0]={'0'};
        mp[2]={'a','b','c'};
        // cout<<mp[2].size();
        mp[3]={'d','e','f'};
        mp[4]={'g','h','i'};
        mp[5]={'j','k','l'};
        mp[6]={'m','n','o'};
        mp[7]={'p','q','r','s'};
        mp[8]={'t','u','v'};
        mp[9]={'w','x','y','z'};
        // cout<<s[0];
        int ele1=s[0]-'0';
        int ele2=s[1]-'0';
        int ele3=s[2]-'0';
        int ele4=s[3]-'0';
        // cout<<mp[ele1].size();
        // cout<<mp[ele2].size();
        // cout<<mp[ele3].size();
        // cout<<mp[ele4].size();
        for(int i=0;i<mp[ele1].size();i++){
            for(int j=0;j<mp[ele2].size();j++){
                 for(int k=0;k<mp[ele3].size();k++){
                      for(int l=0;l<mp[ele4].size();l++){
                        temp="";
                        if(mp[ele1][i]!='0')temp=mp[ele1][i];
                        if(mp[ele2][j]!='0')temp+=mp[ele2][j];
                        if(mp[ele3][k]!='0')temp+=mp[ele3][k];
                        if(mp[ele4][l]!='0')temp+=mp[ele4][l];
                        ans.push_back(temp);                        
                    }
                 }    
             }
        }
        return ans;
        
    }
};