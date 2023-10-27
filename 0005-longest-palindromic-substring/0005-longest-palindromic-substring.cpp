class Solution {
public:
    string longestPalindrome(string s) {
        
        int i,l,r;
        int len=0,st=0,end=0;

        //odd length 

        for(i=0;i<s.size();i++){
            l=i;r=i;
            while(l>=0 and r<s.size()){
                if(s[l]==s[r]){
                    l--;r++;
                }
                else break;
            }
            if(len<(r-l-1)){
                len=r-l-1;
                st=l+1;
                end=r-1;
            }
        }

        if(s.size()==1)return s.substr(st,len);
                        
        //even length

        for(i=0;i<s.size();i++){
             l=i;r=i+1;
            while(l>=0 and r<s.size()){
                if(s[l]==s[r]){
                    l--;r++;
                }
                else break;
            }
            if(len<(r-l-1)){
                len=r-l-1;
                st=l+1;
                end=r-1;
            }            
        }
        return s.substr(st,len);
    }
};