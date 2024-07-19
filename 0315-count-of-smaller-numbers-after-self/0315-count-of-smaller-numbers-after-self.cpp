#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order  {(*A.find_by_order(ind))->ele at ind index}, order_of_key {A.order_of_key(val)->no. of ele less than val}

class Solution {
public:
    vector<int> countSmaller(vector<int>& arr) {
        pbds A;
        vector<int>ans;
        int i,n=arr.size();
        for(i=n-1;i>=0;i--){
            A.insert(arr[i]);
            ans.push_back(A.order_of_key(arr[i]));
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};