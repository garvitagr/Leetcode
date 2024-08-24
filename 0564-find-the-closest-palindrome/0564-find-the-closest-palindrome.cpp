class Solution {
public:
    long long create(long long prefix,int odd){
        if(odd){
            string pre=to_string(prefix);
            string suf=pre.substr(0,pre.size()-1);
            reverse(suf.begin(),suf.end());
            string ans=pre+suf;
            return stoll(ans);
        }
        else{
            string pre=to_string(prefix);
            string suf=pre.substr(0,pre.size());
            reverse(suf.begin(),suf.end());
            string ans=pre+suf;
            return stoll(ans);
        }
    }

    string nearestPalindromic(string s) {
        int n=s.size();
        int mid=n/2;
        long long number=stoll(s);
        mid=(n&1?mid+1:mid);
        long long prefix=stoll(s.substr(0,mid));
        vector<long long>possible;
        long long ans=INT_MIN;

        if(n&1){
            possible.push_back(create(prefix,1));
            possible.push_back(create(prefix+1,1));
            possible.push_back(create(prefix-1,1));
        }
        else{
            possible.push_back(create(prefix,0));
            possible.push_back(create(prefix+1,0));
            possible.push_back(create(prefix-1,0));
        }   
        possible.push_back((long long)(pow(10,n)+1));
        possible.push_back((long long)(pow(10,n-1)-1));

        for(int i=0;i<possible.size();i++){
            if(possible[i]==number)continue;
            long long prevdif=abs(number-ans);
            long long thisdif=abs(number-possible[i]);
            if(thisdif<prevdif)ans=possible[i];
            else if(thisdif==prevdif)ans=min(ans,possible[i]);
        }
        return to_string(ans);
    }
};