class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int i,ones=0;
        for(i=0;i<s.size();i++){
            if(s[i]=='1')ones++;
        }
        s[s.size()-1]='1';
        ones--;
        for(i=0;i<ones;i++){
            s[i]='1';
        }
        for(i=ones;i<s.size()-1;i++){
            s[i]='0';
        }
        return s;
    }
};