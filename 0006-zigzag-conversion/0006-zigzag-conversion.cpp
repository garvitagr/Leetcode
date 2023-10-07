class Solution {
public:
    string convert(string s, int rows) {
        if(rows==1)return s;
        int i,f=0,j=0,d=0,p,q;
        string ans;
        vector<vector<char>>v(1007,vector<char>(1007,0));
        bool nikal=false;

        while(true){
            f=0;
            for(i=0;i<rows;i++){
                if(j==s.size()){
                    nikal=true;
                    break;
                }
                p=f++;q=d;
                v[p][q]=(s[j++]);
                // cout<<p<<" "<<q<<(char)s[j-1]<<endl;
            }
            f=rows-2;
            if(nikal)break;
            for(i=0;i<rows-2;i++){
                if(s.size()==j){
                    nikal=true;
                    break;
                }
                p=f--;q=++d;
                v[p][q]=(s[j++]);
                // cout<<p<<" "<<q<<(char)s[j-1]<<endl;
            }
            if(nikal)break;
            d++;
        }
        // cout<<d;
        for(i=0;i<rows;i++){
            for(j=0;j<=d;j++){
            // cout<<v[i][j];
            if(v[i][j]!='\0')ans+=v[i][j];
            }
        }
        return ans;
    }
};