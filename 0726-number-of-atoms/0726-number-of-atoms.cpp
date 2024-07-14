class Solution {
public:
    string countOfAtoms(string formula) {
        int i=0,n=formula.size();
        stack<unordered_map<string,int>>st;
        st.push(unordered_map<string,int>());
        while(i<n){
            if(formula[i]=='('){
                st.push(unordered_map<string,int>());
                i++;
            }
            else if(formula[i]==')'){
                unordered_map<string,int>cur=st.top();
                st.pop();
                i++;

                string times;
                while(i<n and isdigit(formula[i])){
                    times+=formula[i++];
                }
                if(times.size()){
                    int count=stoi(times);
                    for(auto it:cur){
                        cur[it.first]=it.second*count;
                    }
                }
                for(auto it:cur){
                    st.top()[it.first]+=it.second;
                }
            }
            else{
                string element;
                element+=formula[i++];
                while(i<n and islower(formula[i])){
                    element+=formula[i++];
                }
                string times;
                while(i<n and isdigit(formula[i])){
                    times+=formula[i++];
                }
                int count;
                if(times.empty())count=1;
                else count=stoi(times);

                st.top()[element]+=count;
                
            }
        }

        string ans;
        map<string,int>mp(st.top().begin(),st.top().end());
        for(auto it:mp){
            ans+=it.first;
            string count=to_string(it.second);
            if(count!="1")ans+=count;
        }
        return ans;
    }
};