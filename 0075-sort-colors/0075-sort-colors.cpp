class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> v(3,0);
        for(int i:nums){
            v[i]++;
        }
        int i=0;
        while(v[0]--){
            nums[i++]=0;          
        }
        
        while(v[1]--) nums[i++]=1;
        
        while(v[2]--) nums[i++] = 2;
        for(int i=0;i<nums.size();i++){
            cout << nums[i];
        }

        
    }
};