class Solution {
public:
    vector<int> asteroidCollision(vector<int>& v) {
        stack<int> s;
        int n = v.size();
        vector<int> ans;
        s.push(v[0]);
        int i=1;

        while(i!=n){
            if(!s.empty() && s.top()>=0 && v[i]<0){
                if(abs(s.top())<abs(v[i])){
                    s.pop();
                    continue;  
                }
                else if(abs(s.top())==abs(v[i])){
                    s.pop();
                }

            }
            else {
                s.push(v[i]);
            }
            i++;

        }

        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();

        }
        reverse(ans.begin(),ans.end());
        return ans;


        
        
    }
};