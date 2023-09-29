class Solution {
public:
    string reverseVowels(string s) {
        int i=0,j=s.size()-1;
        // cout<<i<<" "<<j<<endl;
        while(i<j){
          cout<<i<<" "<<j<<endl;
while((i<s.size())and (s[i]!='a' and s[i]!='e' and s[i]!='i' and s[i]!='o' and s[i]!='u' and s[i]!='A' and s[i]!='E' and s[i]!='I' and s[i]!='O' and s[i]!='U' ))i++;
while((j>=0)and (s[j]!='a' and s[j]!='e' and s[j]!='i' and s[j]!='o' and s[j]!='u' and s[j]!='A' and s[j]!='E' and s[j]!='I' and s[j]!='O' and s[j]!='U' ))j--;
          cout<<i<<" "<<j<<endl;
          if(i>j)return s;
          swap(s[i],s[j]);
          i++;j--;  
        }
        return s;
    }
};