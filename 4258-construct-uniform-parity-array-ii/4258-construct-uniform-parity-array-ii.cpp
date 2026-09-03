class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n,0);
        int j=-1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(nums[i]%2==1){
                j=i;
                break;
            }
        }
        if(j==-1) return true;
        v[j]=nums[j];

        for(int i=0;i<n;i++){
            if(i!=j){
                if(nums[i]%2==0){
                    if(nums[i]-nums[j]>=1){
                        v[i]=nums[i]-nums[j];
                    }

                }
                else{
                    v[i]=nums[i];
                }

            }

        }
        for(int x:v){
            if(x%2==0) return false; 
        }
        return true;

        
    }
};