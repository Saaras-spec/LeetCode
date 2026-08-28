
class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        vector<int> v;
        vector<vector<int>> ans;

        for(int i=0;i<score.size();i++){
            v.push_back(score[i][k]);

        }
        sort(v.begin(),v.end(),greater<int>());
        for(int i=0;i<v.size();i++){
            for(int j=0;j<score.size();j++){
                if(v[i]==score[j][k]){
                    ans.push_back(score[j]);
                }
            }
        }
        
        return ans;
        
    }
};