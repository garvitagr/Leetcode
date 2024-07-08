class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int>q;
        for(int i=1;i<=n;i++)q.push(i);
        while(1){
            if(q.size()==1)return q.front();
            for(int i=0;i<k-1;i++){
                int val=q.front();
                q.pop();
                q.push(val);
            }
            q.pop();
        }
        return 1;
    }
};