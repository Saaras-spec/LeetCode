class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int c=0;
        int c2=0;
        int m=-1;
        sort(nums.begin(),nums.end());
        int x=nums[0];

        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                if(x!=nums[i]){
                    if(c>c2){
                        c2=c;
                        m=x;                        
                    }else if(c==c2){
                        m=min(m,x);
                    }
                    c=0;
                    x=nums[i];
                    
                }
                c++;

            }

        }
        if(c>c2){
            m=x;
        }else if(c==c2){
            m=min(m,x);
        }
        return m;
        
    }
};