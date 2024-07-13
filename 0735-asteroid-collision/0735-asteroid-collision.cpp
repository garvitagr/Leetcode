class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        int i,n=asteroids.size();
        for(i=0;i<asteroids.size();i++){
            if(asteroids[i]>=0)st.push(asteroids[i]);
            else if(st.empty() or (!st.empty() and st.top()<0))st.push(asteroids[i]);
            else{
                bool add=true;
                int val=abs(asteroids[i]);
                while(!st.empty()){
                    if(st.top()<0)break;
                    if(val>st.top())st.pop();
                    else if(val==st.top()){
                        st.pop();
                        add=false;
                        break;
                    }
                    else{
                        add=false;
                        break;
                    }                    
                }
                if(add)st.push(asteroids[i]);
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};