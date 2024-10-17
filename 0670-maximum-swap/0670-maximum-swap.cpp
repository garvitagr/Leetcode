class Solution {
public:
    string findMax(string ahead){
        int i,ans=stoi(ahead);
        for(i=1;i<ahead.size();i++){
            string temp=ahead;
            swap(temp[0],temp[i]);
            int thisAns=stoi(temp);
            ans=max(ans,thisAns);
        }
        return to_string(ans);
    }

    int maximumSwap(int num) {
        string s=to_string(num);
        string temp=s;
        sort(temp.begin(),temp.end());
        reverse(temp.begin(),temp.end());
        for(int i=0;i<temp.size();i++){
            if(temp[i]!=s[i]){
                string ahead=s.substr(i);
                string ans=s.substr(0,i)+findMax(ahead);
                return stoi(ans);
            }
        }
        return num;
    }
};