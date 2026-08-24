class Solution {
public:
    vector<int> min(vector<int>& v){
        vector<int> s;
        int min = v[0];
        int idx=0;
        for(int i=0;i<v.size();i++){
            if(v[i]<min){
                min = v[i];
                idx=i;
            }
        }
        s.push_back(min);
        s.push_back(idx);
        return s;
    }
    vector<int> numberGame(vector<int>& nums) {
        vector<int> v;
        while(nums.size()!=0){
            int a = min(nums)[0];
            nums.erase(nums.begin()+ min(nums)[1]);
            int b = min(nums)[0];
            nums.erase(nums.begin()+min(nums)[1]);
            v.push_back(b);
            v.push_back(a);
        }
        return v;

        
        
    }
};