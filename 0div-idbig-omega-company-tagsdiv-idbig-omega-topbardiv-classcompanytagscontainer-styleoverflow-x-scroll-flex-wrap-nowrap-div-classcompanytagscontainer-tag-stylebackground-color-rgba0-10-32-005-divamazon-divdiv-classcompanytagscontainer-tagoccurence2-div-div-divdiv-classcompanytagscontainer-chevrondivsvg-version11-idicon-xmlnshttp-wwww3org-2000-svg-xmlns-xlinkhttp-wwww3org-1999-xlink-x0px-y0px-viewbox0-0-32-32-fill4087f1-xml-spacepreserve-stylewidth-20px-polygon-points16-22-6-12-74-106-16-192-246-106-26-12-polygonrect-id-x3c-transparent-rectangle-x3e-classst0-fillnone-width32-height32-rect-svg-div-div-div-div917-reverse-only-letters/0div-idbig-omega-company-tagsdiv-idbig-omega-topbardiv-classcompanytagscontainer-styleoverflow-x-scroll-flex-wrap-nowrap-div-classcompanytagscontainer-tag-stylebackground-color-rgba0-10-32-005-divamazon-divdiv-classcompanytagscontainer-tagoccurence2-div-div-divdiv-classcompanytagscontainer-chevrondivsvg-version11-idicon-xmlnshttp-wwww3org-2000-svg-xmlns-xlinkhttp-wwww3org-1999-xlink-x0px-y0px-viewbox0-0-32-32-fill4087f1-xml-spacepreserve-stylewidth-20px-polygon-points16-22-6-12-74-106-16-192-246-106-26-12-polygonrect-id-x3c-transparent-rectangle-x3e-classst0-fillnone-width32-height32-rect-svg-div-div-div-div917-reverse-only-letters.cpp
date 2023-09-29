class Solution {
public:
    string reverseOnlyLetters(string s) {
        int i=0,j=s.size()-1;
        while(i<j){
            while (i<s.size() and !( (s[i]>='a' and s[i]<='z')  or  (s[i]>='A' and s[i]<='Z')  ) )i++;
            while (j>=0 and !( (s[j]>='a' and s[j]<='z')  or  (s[j]>='A' and s[j]<='Z')  ) )j--;
            if(i>j)return s;
            else swap(s[i],s[j]);
            i++;j--;
        }
        return s;
    }
};