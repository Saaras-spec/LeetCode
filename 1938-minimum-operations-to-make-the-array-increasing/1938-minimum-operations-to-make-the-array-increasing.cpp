class Solution {
public:
    int minOperations(vector<int>& nums) {
        int s1=0;
        for(int x:nums){
            s1+=x;
        }
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=nums[i-1]){
                nums[i]=nums[i-1]+1;
            }
        }
        int s2=0;
        for(int x:nums){
            s2+=x;
        }
        return s2-s1;
        
    }
};