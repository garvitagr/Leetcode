class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int i,n=s.size(),ans=0;
        string temp;
        if(n==1)return 0;
        stack<char>st;
        if(x>y){
            for(i=0;i<n;i++){
                if(s[i]!='b')st.push(s[i]);
                else if(!st.empty() and st.top()=='a')ans+=x,st.pop();
                else st.push(s[i]);
            }
            while(!st.empty())temp+=st.top(),st.pop();
            reverse(temp.begin(),temp.end());
            s=temp;
            for(i=0;i<temp.size();i++){
                if(s[i]!='a')st.push(s[i]);
                else if(!st.empty() and st.top()=='b')ans+=y,st.pop();
                else st.push(s[i]);
            }
        }
        else{
            for(i=0;i<n;i++){
                if(s[i]!='a')st.push(s[i]);
                else if(!st.empty() and st.top()=='b')ans+=y,st.pop();
                else st.push(s[i]);
            }
            while(!st.empty())temp+=st.top(),st.pop();
            reverse(temp.begin(),temp.end());
            s=temp;
            for(i=0;i<temp.size();i++){
                if(s[i]!='b')st.push(s[i]);
                else if(!st.empty() and st.top()=='a')ans+=x,st.pop();
                else st.push(s[i]);
            }
        }
        return ans;
    }
};