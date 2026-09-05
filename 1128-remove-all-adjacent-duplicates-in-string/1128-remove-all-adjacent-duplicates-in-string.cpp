class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> s1;
        

        for(char c : s){
            if(!s1.empty()){
                if(c==s1.top()){
                    s1.pop();
                }
                else{
                    s1.push(c);
                }
            }
            else s1.push(c);
        }
        string ans="";
        while(!s1.empty()){
            ans+=s1.top();
            s1.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }

};