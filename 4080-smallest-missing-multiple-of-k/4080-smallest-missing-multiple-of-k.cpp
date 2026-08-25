class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<int>  v(101,0);
        for(int i:nums){
            v[i] =1;
        }
        int x =0;
        for(int i=1;i<v.size();i++){
            if(i%k==0){
                if(v[i]==0){
                    x=i;
                    break;
                    

                }
            }
        }
        if(x==0){
            int s = 100/k;
            return k*(s+1);


        }
        return x;

        
    }
};