class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ct=0;
        for(int i=0;i<details.size();i++){
            string age=details[i].substr(11,2);
            if(age[0]-'0'>6 or (age[0]-'0'==6 and age!="60"))ct++;
        }
        return ct;
    }
};