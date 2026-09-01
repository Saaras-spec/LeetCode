class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int p =0;
        int idx=0;
        int b=1;

        for(int i=1;i<arr.size();i++){
            if(arr[idx]>arr[i]){
                idx=i;
                
            }
            if(arr[b]<arr[i]){
                b=i;
            }
            if(i!=arr.size()-1 && arr[i]>arr[idx] && arr[i]<arr[b]){
                if(arr[i]-arr[idx]>p){
                    p=arr[i]-arr[idx];

                }
                continue;

            } 
            else{
                if(arr[i]-arr[idx]>p){
                    p = arr[i]-arr[idx];
                }

            }

        }
        return p;
        
    }
};