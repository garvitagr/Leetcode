class Solution {
public:
    int numberOfSubstrings(string s) {
        int i,ans=0,a=-1,b=-1,c=-1,temp,n=s.size();

        for(i=n-1;i>=0;i--){
            if(s[i]=='a'){
                a=i;
                if(b==-1 or c==-1)continue;
                temp=n-1-max(b,c);
                ans+=temp+1;
            }
            else if(s[i]=='b'){
                b=i;
                if(a==-1 or c==-1)continue;
                temp=n-1-max(a,c);
                ans+=temp+1;
            }
            else{
                c=i;
                if(a==-1 or b==-1)continue;
                temp=n-1-max(a,b);
                ans+=temp+1;
            }
        }
        return ans;

    }
};