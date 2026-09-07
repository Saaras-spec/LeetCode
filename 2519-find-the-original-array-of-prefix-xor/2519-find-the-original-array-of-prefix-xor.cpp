class Solution {
public:
    vector<int> findArray(vector<int>& pref) {

        int n=pref.size();
        if(n==1) return pref;
        vector<int> v(n,0);
        v[0]=pref[0];
        vector<int> x(n,0);
        x[1]=v[0];

        for(int i=1;i<n-1;i++){
            v[i] = x[i]^pref[i];
            x[i+1] = x[i]^v[i];
        }
        v[n-1]=x[n-1]^pref[n-1];
        return v;
        
    }
};