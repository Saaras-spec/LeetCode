class Solution {
public:

    void maxheap(int i,vector<int>& arr , int n){
        int lt = 2*i +1;
        int rt = 2*i +2;
        //int pt = (i-1)/2;
        int l = i;
        if(lt<n && arr[lt]>arr[i]){
            l = lt;
        }
        if(rt<n && arr[rt]>arr[l]){
            l = rt;
        }
        if(l!=i){
            swap(arr[i],arr[l]);
            maxheap(l,arr,n);
        }



    }


    int findKthLargest(vector<int>& nums, int k) {
        //build max heap
        int size = nums.size();
        int rb = size/2 -1;
        for(int i=rb ; i>=0 ; i-- ){
            maxheap(i,nums,size);
        }
        for(int i=size-1;i>=size-k+1;i--){
            swap(nums[0],nums[i]);

            maxheap(0,nums,i);
        }
        return nums[0];

        
    }
};