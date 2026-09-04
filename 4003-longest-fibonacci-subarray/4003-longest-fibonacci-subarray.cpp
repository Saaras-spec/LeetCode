class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int n=nums.size();
        if(n==1) return 1;
        if(n==2) return 2;
        int m=2,count=2;
        int i=0;
        int j=2;
        while(j<n){              
            
            if(nums[i]+nums[i+1]==nums[j]) count++;               
            
            else{
                m =max(m,count);
                count=2;
            }
            i++;
            j++;
        }
        m=max(m,count);
        return m;
    }
};