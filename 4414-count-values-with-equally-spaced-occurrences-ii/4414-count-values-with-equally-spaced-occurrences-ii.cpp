class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        int ans=0;
        for(auto &p : mp){
            vector<int>& pos = p.second;
            if(pos.size()<3) continue;

            int space = pos[1]-pos[0];
            bool check = true;

            for(int i=2;i<pos.size();i++){
                if(space!= pos[i]-pos[i-1]){
                    check = false;
                    break;
                }
            }
            if(check) ans++;
        }
        return ans;
        
    }
};