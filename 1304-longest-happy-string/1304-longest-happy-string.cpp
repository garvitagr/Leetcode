class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans="";
        priority_queue<pair<int,char>>pq;
        if(a)pq.push({a,'a'});
        if(b)pq.push({b,'b'});
        if(c)pq.push({c,'c'});
        
        while(pq.size()>1){
            char ch1=pq.top().second;
            int ct1=pq.top().first;
            pq.pop();
            char ch2=pq.top().second;
            int ct2=pq.top().first;
            pq.pop();
            if(ct1>1){
                ans+=ch1;
                ans+=ch1;
                ct1-=2;
            }
            else {
                ans+=ch1;
                ct1--;
            }
            if(ct2>1 and ct2>=ct1){
                ans+=ch2;
                ans+=ch2;
                ct2-=2;
            }
            else {
                ans+=ch2;
                ct2--;
            }
            if(ct1)pq.push({ct1,ch1});
            if(ct2)pq.push({ct2,ch2});
        }
        if(pq.size()==1){
            int ct=pq.top().first;
            char ch=pq.top().second;
            if(ct>1){
                ans+=ch;
                ans+=ch;
                ct-=2;
            }
            else {
                ans+=ch;
                ct--;
            }
        }

        return ans;
    }
};