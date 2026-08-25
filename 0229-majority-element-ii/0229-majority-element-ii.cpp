class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> v;
        int x = nums[0];
        int c=0;
        for(int i=0;i<nums.size();i++){
            
            if(x!=nums[i]){
                if(c>(nums.size()/3)){
                    v.push_back(x);                    
                }
                x=nums[i];
                c=0;
            }
            c++;
        }
        if(c>(nums.size()/3)) v.push_back(x);
        return v;
        
    }
};